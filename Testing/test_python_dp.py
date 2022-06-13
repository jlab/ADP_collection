from unittest import TestCase, main

import copy
import numpy as np
import sys
sys.path.append("../")

from matrix_chain_multiplication import minmult
from elmamun import elmamun
from binary_search_tree import *
from hmms import *
from alignments import *
from satisfiability import *

PREFIX_GAPC_TRUTH = 'Truth/'
def _get_gapc_answer(fp_answer):
    """Quick&Dirty: Get first element of second line in gapc output."""
    with open(fp_answer, 'r') as f:
        lines = f.readlines()
        parts = [p for p in lines[1].strip().split('(') if p.replace(' ', '') != '']
        return parts[0].split(',')[0].strip()


class matrixchainmultiplication(TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_minmult(self):
        input = [(2,10),(10,50),(50,10),(10,1),(1,20),(20,20)]
        exp = (1460, 2, 20)
        obs = minmult(input)
        self.assertEqual(obs, exp)

        obs_gap = _get_gapc_answer('%s/matrix_chain_multiplication.assert_minmultenum.pass_2.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs[0], int(obs_gap))

        obs_gap = _get_gapc_answer('%s/matrix_chain_multiplication.assert_minmultenumcount.pass_3.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs[0], int(obs_gap))

        obs_gap = _get_gapc_answer('%s/matrix_chain_multiplication.minmult.basicexample.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs[0], int(obs_gap))

        obs_gap = _get_gapc_answer('%s/matrix_chain_multiplication.minmultdepthpp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs[0], int(obs_gap))

        obs_gap = _get_gapc_answer('%s/matrix_chain_multiplication.reject_wrong_candidates.basicexample_noreject.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs[0], int(obs_gap))


class el_mamun(TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_elmamun(self):
        input = [1,'+',2,'*',3,'*',4,'+',5]

        # seller, i.e. maximum
        exp = 81
        obs = elmamun(input, h=np.max)
        self.assertEqual(obs, exp)

        obs_gap = _get_gapc_answer('%s/elmamun.sellerpp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs, int(obs_gap))

        # buyer, i.e. minimum
        exp = 30
        obs = elmamun(input, h=np.min)
        self.assertEqual(obs, exp)

        obs_gap = _get_gapc_answer('%s/elmamun.buyerpp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs, int(obs_gap))

        # violate Bellman's Principle
        exp = -24  # ((1+2)-(3*(4+5)))
        obs = elmamun([1,'+',2,'-',3,'*',4,'+',5], h=np.min)
        self.assertFalse(exp == obs)

        obs_gap = _get_gapc_answer('%s/elmamun.buyerpp.violateBP.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs, int(obs_gap))


class binarysearchtree(TestCase):
    def setUp(self):
        self.probabilities = {
            1:0.22,
            3:0.18,
            4:0.2,
            8:0.05,
            10:0.25,
            11:0.02,
            15:0.08}
        self.tree1 = Branch(
            Branch(Nil(), 1, Branch(Leaf(3), 4, Leaf(8))),
            10,
            Branch(Leaf(11), 15, Nil())
        )
        self.tree2 = Branch(
            Branch(Leaf(1), 3, Leaf(4)),
            8,
            Branch(Leaf(10), 11, Leaf(15))
        )

    def tearDown(self):
        self.tree1 = None
        self.tree2 = None

    def test_mean_access_time(self):
        exp = 2.43
        determine_depth(self.tree1)
        obs = mean_access_time(self.tree1, self.probabilities)
        self.assertEqual(exp, obs)

        exp = 2.7
        determine_depth(self.tree2)
        obs = mean_access_time(self.tree2, self.probabilities)
        self.assertEqual(exp, obs)

    def test_mean_access_time_buttomup(self):
        exp = 2.43
        obs = mean_access_time_bottomup(self.tree1, self.probabilities)
        self.assertAlmostEqual(exp, obs['mean'])

        exp = 2.7
        obs = mean_access_time_bottomup(self.tree2, self.probabilities)
        self.assertAlmostEqual(exp, obs['mean'])

    def test_mean_access_time_abuse(self):
        # you manually need to ensure that tree as been annotated with depth!
        with self.assertRaises(AttributeError):
            obs = mean_access_time(self.tree1, self.probabilities)

        # fails if not all keys are contained in probabilities!
        newtree = Branch(copy.copy(self.tree1), 99, Nil())
        determine_depth(newtree)
        with self.assertRaises(KeyError):
            mean_access_time(newtree, self.probabilities)

    def min_mean_access_time(self):
        exp = (2.15, 1)
        obs = min_mean_access_time([1,3,4,8,10,11,15], self.probabilities)
        self.assertAlmostEqual(exp[0], obs[0])

        obs_gap = _get_gapc_answer('%s/binary_search_tree.matpp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs, float(obs_gap))

        obs_gap = _get_gapc_answer('%s/binary_search_tree.matppcount.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertEqual(obs, float(obs_gap))


class hmm(TestCase):
    def setUp(self):
        self.TRANSITIONS = {
            ('start', 'hoch'): 0.5,
            ('start', 'tief'): 0.5,
            ('hoch', 'hoch'): 0.7,
            ('hoch', 'tief'): 0.3,
            ('tief', 'tief'): 0.6,
            ('tief', 'hoch'): 0.4}

        self.EMISSIONS = {
            ('hoch', 'sonne'): 0.8,
            ('hoch', 'regen'): 0.2,
            ('tief', 'sonne'): 0.1,
            ('tief', 'regen'): 0.9,
            ('start', 'ε'): 1.0,
            ('start', 'ε'): 1.0}

        self.casino_transitions = {
            ('fair','fair'): 0.95,
            ('fair', 'loaded'): 0.05,
            ('loaded', 'loaded'): 0.9,
            ('loaded', 'fair'): 0.1,
            ('start', 'loaded'): 0.5,
            ('start', 'fair'): 0.5}
        self.casino_emissions = {
            ('fair', 1): 1/6,
            ('fair', 2): 1/6,
            ('fair', 3): 1/6,
            ('fair', 4): 1/6,
            ('fair', 5): 1/6,
            ('fair', 6): 1/6,
            ('loaded', 1): 1/10,
            ('loaded', 2): 1/10,
            ('loaded', 3): 1/10,
            ('loaded', 4): 1/10,
            ('loaded', 5): 1/10,
            ('loaded', 6): 1/2,
            ('start', 'ε'): 1.0}

        self.cpg_transitions = {
            ('rich','rich'): 0.63,
            ('rich', 'poor'): 0.37,
            ('poor', 'poor'): 0.63,
            ('poor', 'rich'): 0.37,
            ('start', 'poor'): 0.5,
            ('start', 'rich'): 0.5}
        self.cpg_emissions = {
            ('rich', 'A'): 0.13,
            ('rich', 'C'): 0.37,
            ('rich', 'G'): 0.37,
            ('rich', 'T'): 0.13,
            ('poor', 'A'): 0.37,
            ('poor', 'C'): 0.13,
            ('poor', 'G'): 0.13,
            ('poor', 'T'): 0.37,
            ('start', 'ε'): 1.0}
        self.cpg_input = [x for x in ("GCGGCCGATATACTACAGTTGGCTTGAATGAACCAGGC"
                                      "CCGGCGCGGACAACCTGGGCCCCGGCGGTCGCCCATAC"
                                      "CGCAATGGGAGCCGTTAACTCGCT")]


    def tearDown(self):
        pass

    def test_hmm_sonneregen(self):
        inp = ["sonne", "sonne", "regen", "regen"]

        exp = 0.0326592
        obs = viterbi(inp, "start", self.TRANSITIONS, self.EMISSIONS)
        self.assertAlmostEqual(exp, obs)

        obs_gap = _get_gapc_answer('%s/hmm_sonneregen.viterbistatesmult.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

        with self.assertRaises(AssertionError):
            viterbi(inp, "startxx", self.TRANSITIONS, self.EMISSIONS)

        with self.assertRaises(AssertionError):
            emissions = copy.copy(self.EMISSIONS)
            emissions.update({('falsch', 'sonne'): 0.9})
            viterbi(inp, "start", self.TRANSITIONS, emissions)

        exp = 0.059466
        obs = forward(inp, "start", self.TRANSITIONS, self.EMISSIONS)
        self.assertAlmostEqual(exp, obs)

        obs_gap = _get_gapc_answer('%s/hmm_sonneregen.fwd.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

    def test_hmm_casino(self):
        inp = [1,5,6,2,6]

        exp = 8.20125e-05
        obs = viterbi(inp, "start", self.casino_transitions, self.casino_emissions)
        self.assertAlmostEqual(exp, obs)

        obs_gap = _get_gapc_answer('%s/hmm_casino.viterbistatesmult.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))


        exp = 0.000187711
        obs = forward(inp, "start", self.casino_transitions, self.casino_emissions)
        self.assertAlmostEqual(exp, obs)

        obs_gap = _get_gapc_answer('%s/hmm_casino.fwd.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

    def test_hmm_cpg(self):
        exp = 4.4896241716888033e-72
        obs = viterbi(self.cpg_input, "start", self.cpg_transitions, self.cpg_emissions)
        self.assertAlmostEqual(exp, obs)

        obs_gap = _get_gapc_answer('%s/hmm_cpg.viterbistatesmult.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

        exp = 3.559918247841254e-60
        obs = forward(self.cpg_input, "start", self.cpg_transitions, self.cpg_emissions)
        self.assertAlmostEqual(exp, obs)

        obs_gap = _get_gapc_answer('%s/hmm_cpg.fwd.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

class align(TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_needlemanwunsch(self):
        exp = -3
        obs = needlemanwunsch("FREIZEIT", "ZEITGEIST")
        self.assertEqual(exp, obs)
        obs_gap = _get_gapc_answer('%s/alignments.ins_needlemanwunsch_similaritycount.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))
        obs_gap = _get_gapc_answer('%s/alignments.ins_needlemanwunsch_similaritypp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

    def test_semiglobal(self):
        exp = 1
        obs = semiglobal("ZEITGEIST", "EILS")
        self.assertEqual(exp, obs)
        obs_gap = _get_gapc_answer('%s/alignments.ins_semiglobal_similaritycount.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))
        obs_gap = _get_gapc_answer('%s/alignments.ins_semiglobal_similaritypp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

    def test_endGapFree(self):
        exp = 2
        obs = endGapFree("FREIZEILT", "ZEITGEIST")
        self.assertEqual(exp, obs)
        obs_gap = _get_gapc_answer('%s/alignments.ins_endgapfree_similaritycount.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))
        obs_gap = _get_gapc_answer('%s/alignments.ins_endgapfree_similaritypp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

    def test_smithwaterman(self):
        exp = 4
        obs = smithwaterman("EISZEITEN", "GEZEITIG")
        self.assertEqual(exp, obs)
        obs_gap = _get_gapc_answer('%s/alignments.ins_smithwaterman_similaritycount.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))
        obs_gap = _get_gapc_answer('%s/alignments.ins_smithwaterman_similaritypp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

    def test_smithwaterman(self):
        exp = -2
        obs = gotoh("CG", "CCGA")
        self.assertEqual(exp, obs)
        obs_gap = _get_gapc_answer('%s/alignments.ins_gotoh_similaritycount.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))
        obs_gap = _get_gapc_answer('%s/alignments.ins_gotoh_similaritypp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertAlmostEqual(obs, float(obs_gap))

class sat(TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def _parse_gapc_answer(self, fp_file):
        assignments = []
        with open(fp_file, "r") as f:
            for line in f.readlines():
                if line.startswith("( ( "):
                    pretty = line.split(' , ')[1].split()[0]
                    assignment = []
                    for i in range(len(pretty)):
                        if pretty[i] == 'T':
                            assignment.append(True)
                        elif pretty[i] == 'F':
                            assignment.append(False)
                    assignments.append(tuple(assignment))
        return assignments

    def test_satisfiability(self):
        exp = {(True, True, True),
               (True, False, True),
               (True, False, False),
               (False, True, True)}
        obs = satisfiability("PP-&-NP")
        self.assertSetEqual(exp, set(obs))

        obs_gap = self._parse_gapc_answer('%s/satisfiability.ins_sateqapp.foo.out' % PREFIX_GAPC_TRUTH)
        self.assertSetEqual(set(obs_gap), set(obs))

if __name__ == '__main__':
    main()
