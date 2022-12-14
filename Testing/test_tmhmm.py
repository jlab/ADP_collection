#!/usr/bin/env python
# coding: utf-8
import subprocess
import sys
import tempfile
import shutil
import os

from unittest import TestCase, main

sys.path.append("../")
from tmhmm import (parse_model, model_to_graphviz, model_to_grammar,
                   generic_sig_algs, generate_gapc)


def run_cmd(cmd):
    with subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE) as task:
        return task.stdout.read().decode('ascii').rstrip().split('\n')


ARCHTRIPLE = run_cmd('gcc -dumpmachine')[0]

PREFIX_GAPC = run_cmd('which gapc')[0]
PREFIX_GAPC = '/'.join(PREFIX_GAPC.split('/')[:-2])


class tmhmm(TestCase):
    def setUp(self):
        self.DEBUG = False

        self.fp_model = "../TMHMM/TMHMM2.0.model"
        self.fp_truth_graph = "Truth/tmhmm_graph.dot"
        self.fp_truth_grammar = "Truth/tmhmm_grammar.gap"
        self.fp_truth_comps = "Truth/tmhmm_genericcomponents.gap"
        self.fp_tmpdir = tempfile.mkdtemp()
        shutil.copyfile("../ext_tmhmm.hh", self.fp_tmpdir+"/ext_tmhmm.hh")
        if self.DEBUG:
            print("tmp dir is %s" % self.fp_tmpdir)
        self.seq_mini = "EKNWSALLTAVVIILTIAG"
        self.seq_example = (
            "MEILCEDNTSLSSIPNSLMQVDGDSGLYRNDFNSRDANSSDASNWTIDGENRTNLSFEGYLPPT"
            "CLSILHLQEKNWSALLTAVVIILTIAGNILVIMAVSLEKKLQNATNYFLMSLAIADMLLGFLVM"
            "PVSMLTILYGYRWPLPSKLCAVWIYLDVLFSTASIMHLCAISLDRYVAIQNPIHHSRFNSRTKA"
            "FLKIIAVWTISVGVSMPIPVFGLQDDSKVFKQGSCLLADDNFVLIGSFVAFFIPLTIMVITYFL"
            "TIKSLQKEATLCVSDLSTRAKLASFSFLPQSSLSSEKLFQRSIHREPGSYTGRRTMQSISNEQK"
            "ACKVLGIVFFLFVVMWCPFFITNIMAVICKESCNEHVIGALLNVFVWIGYLSSAVNPLVYTLFN"
            "KTYRSAFSRYIQCQYKENRKPLQLILVNTIPALAYKSSQLQAGQNKDSKEDAEPTDNDCSMVTL"
            "GKQQSEETCTDNINTVNEKVSCV")

    def tearDown(self):
        if self.DEBUG:
            print("delete %s" % self.fp_tmpdir)
        shutil.rmtree(self.fp_tmpdir)

    def test_graphviz(self):
        model = parse_model(self.fp_model)

        # test that 135 states get parsed
        self.assertEqual(len(model), 135)

        dot = model_to_graphviz(model)
        with open(self.fp_truth_graph, "r") as f:
            exp = ''.join(f.readlines())
            self.assertEqual(exp, dot)

    def test_grammar(self):
        model = parse_model(self.fp_model)

        obs = model_to_grammar(model)
        with open(self.fp_truth_grammar, "r") as f:
            exp = ''.join(f.readlines())
            self.assertEqual(exp, obs)

    def test_generic_components(self):
        obs = generic_sig_algs()
        with open(self.fp_truth_comps, "r") as f:
            exp = ''.join(f.readlines())
            self.assertEqual(exp, '\n'.join(obs))

    def test_generate_gapc(self):
        fp_code = os.path.join(self.fp_tmpdir, "tmhmm.gap")
        generate_gapc(self.fp_model, fp_code)

        cmd_gapc = 'cd %s && gapc -p "(alg_viterbi_bit %% alg_viterbi)" %s' % (
            self.fp_tmpdir, fp_code)
        result_gapc = run_cmd(cmd_gapc)
        self.assertEqual(result_gapc, [""])

        cmd_make = 'cd %s && make -f out.mf' % (self.fp_tmpdir)
        result_make = run_cmd(cmd_make)
        self.assertEqual(len(result_make), 7)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, self.seq_mini)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].strip()

        # cmp with tmhmm-2.0c/bin>./decodeanhmm.Linux_x86_64 \
        # ../lib/TMHMM2.0.model ../testcase1.fasta -optionfile \
        # ../lib/TMHMM2.0.options -viterbi -PrintPred -PrintSeq -PrintTag \
        # -PrintScore -PrintStat -PrintNumbers -nonormalize -nobits -plp
        # line: %score Viterbi 56.430404 (2.970021 per character)
        exp = "( 56.4304 , 3.10876e-25 )"
        self.assertEqual(exp, obs)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, self.seq_example)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].strip()

        # %score Viterbi 1348.784605 (2.863662 per character)
        # due to numeric instability, raw prob is rounded to 0, that's why we
        # need bits or logspace for real inputs
        exp = "( 1348.78 , 0 )"
        self.assertEqual(exp, obs)

    def test_generate_gapc_label(self):
        fp_code = os.path.join(self.fp_tmpdir, "tmhmm.gap")
        generate_gapc(self.fp_model, fp_code)

        cmd_gapc = ('cd %s && gapc -p "(alg_viterbi_bit %% alg_viterbi) '
                    '* alg_label" %s') % (
            self.fp_tmpdir, fp_code)
        result_gapc = run_cmd(cmd_gapc)
        self.assertEqual(result_gapc, [""])

        cmd_make = 'cd %s && make -f out.mf' % (self.fp_tmpdir)
        result_make = run_cmd(cmd_make)
        self.assertEqual(len(result_make), 7)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, self.seq_mini)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].split(' , ')[-1].split(')')[0].strip()

        # cmp with tmhmm-2.0c/bin>./decodeanhmm.Linux_x86_64 \
        # ../lib/TMHMM2.0.model ../testcase1.fasta -optionfile \
        # ../lib/TMHMM2.0.options -viterbi -PrintPred -PrintSeq -PrintTag \
        # -PrintScore -PrintStat -PrintNumbers -nonormalize -nobits -plp
        # lines starting with "?V"
        exp = "OOOOOOOOOOOOOOOOOOO"
        self.assertEqual(exp, obs)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, self.seq_example)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].split(' , ')[-1].split(')')[0].strip()

        # lines starting with "?V"
        exp = ("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
               "ooooooooooooooMMMMMMMMMMMMMMMMMMMMMMMiiiiiiiiiiiiMMMMMMMMMMMMM"
               "MMMMMMMMMMooooooooooooooMMMMMMMMMMMMMMMMMMMMMMMiiiiiiiiiiiiiii"
               "iiiiiMMMMMMMMMMMMMMMMMMMMMMMoooooooooooooooooooMMMMMMMMMMMMMMM"
               "MMMMMMMMiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"
               "iiiiiiiiiiiiiiMMMMMMMMMMMMMMMMMMMMMMMoooooooooMMMMMMMMMMMMMMMM"
               "MMMMMMMiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"
               "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii")
        self.assertEqual(exp, obs)

    def test_gapc_fwd(self):
        fp_code = os.path.join(self.fp_tmpdir, "tmhmm.gap")
        generate_gapc(self.fp_model, fp_code)

        cmd_gapc = ('cd %s && gapc -p "alg_fwd_bit" %s') % (
            self.fp_tmpdir, fp_code)
        result_gapc = run_cmd(cmd_gapc)
        self.assertEqual(result_gapc, [""])

        cmd_make = 'cd %s && make -f out.mf' % (self.fp_tmpdir)
        result_make = run_cmd(cmd_make)
        self.assertEqual(len(result_make), 7)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, self.seq_mini)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1]
        # compare with line "%score FW 55.451140 (2.918481 per character)"
        # from program TMHMM
        exp = "55.4511"
        self.assertEqual(exp, obs)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, self.seq_example)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1]
        # compare with line "%score FW 1344.372166 (2.854293 per character)"
        # from program TMHMM
        exp = "1344.3722"
        self.assertEqual(exp, obs)

if __name__ == '__main__':
    main()
