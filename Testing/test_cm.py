#!/usr/bin/env python
# coding: utf-8
import subprocess
import sys
import tempfile
import shutil
import os

from unittest import TestCase, main

sys.path.append("../")
from cm import (cm2gapc, model2probs, model2grammar, parse_cm, model2probdot,
                patch_report_insideoutside, acm2probdot)
from test_tmhmm import run_cmd

class cm(TestCase):
    def setUp(self):
        self.DEBUG = False
        self.fp_tmpdir = tempfile.mkdtemp()
        if self.DEBUG:
            print("tmp dir is %s" % self.fp_tmpdir)


    def tearDown(self):
        if self.DEBUG:
            print("delete %s" % self.fp_tmpdir)
        shutil.rmtree(self.fp_tmpdir)

    def test_cyk_mini(self):
        model = "RFmini"
        sequence = "cccac"

        cm2gapc("%s.cm" % model, self.fp_tmpdir + "/%s" % model, verbose=sys.stderr)

        cmd_gapc = 'cd %s && gapc -p "alg_cyk" %s.gap' % (
            self.fp_tmpdir, model)
        result_gapc = run_cmd(cmd_gapc)
        self.assertEqual(result_gapc, [""])

        cmd_make = 'cd %s && make -f out.mf' % (self.fp_tmpdir)
        result_make = run_cmd(cmd_make)
        self.assertEqual(len(result_make), 7)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, sequence)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].strip()
        # validated against cmalign-1.1.4 -g --cpu 1 --cyk --notrunc --nonbanded --tfile tmp.parsetree RFmini.cm tmp.fasta
        self.assertAlmostEqual(float(obs), -19.044)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, 'a')
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].strip()
        # validated against cmalign-1.1.4 -g --cpu 1 --cyk --notrunc --nonbanded --tfile tmp.parsetree RFmini.cm tmp.fasta
        self.assertAlmostEqual(float(obs), -21.887)

    def test_cyk_micro(self):
        model = "RFmicro"
        sequence = "cccac"

        cm2gapc("%s.cm" % model, self.fp_tmpdir + "/%s" % model, verbose=sys.stderr)

        cmd_gapc = 'cd %s && gapc -p "alg_cyk" %s.gap' % (
            self.fp_tmpdir, model)
        result_gapc = run_cmd(cmd_gapc)
        self.assertEqual(result_gapc, [""])

        cmd_make = 'cd %s && make -f out.mf' % (self.fp_tmpdir)
        result_make = run_cmd(cmd_make)
        self.assertEqual(len(result_make), 7)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, sequence)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].strip()
        # validated against cmalign-1.1.4 -g --cpu 1 --cyk --notrunc --nonbanded --tfile tmp.parsetree RFmicro.cm tmp.fasta
        self.assertAlmostEqual(float(obs), -31.909)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, 'a')
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].strip()
        # validated against cmalign-1.1.4 -g --cpu 1 --cyk --notrunc --nonbanded --tfile tmp.parsetree RFmicro.cm tmp.fasta
        self.assertAlmostEqual(float(obs), -47.851)

    def test_cyk_micro(self):
        model = "RF00005"
        sequence = "GGGCCCAUAGCUCAGUGGUAGAGUGCCUCCUUUGCAAGGAGGAUGCCCUGGGUUCGAAUCCCAGUGGGUCCA"

        cm2gapc("%s.cm" % model, self.fp_tmpdir + "/%s" % model, verbose=sys.stderr)

        cmd_gapc = 'cd %s && gapc -p "alg_cyk" %s.gap' % (
            self.fp_tmpdir, model)
        result_gapc = run_cmd(cmd_gapc)
        self.assertEqual(result_gapc, [""])

        cmd_make = 'cd %s && make -f out.mf' % (self.fp_tmpdir)
        result_make = run_cmd(cmd_make)
        self.assertEqual(len(result_make), 7)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, sequence)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].strip()
        # validated against cmalign-1.1.4 -g --cpu 1 --cyk --notrunc --nonbanded --tfile tmp.parsetree RF00005.cm tmp.fasta
        self.assertAlmostEqual(float(obs), 70.544)

    def test_inside_micro(self):
        model = "RFmicro"
        sequence = "GGGCCCAUAGCUC"

        cm2gapc("%s.cm" % model, self.fp_tmpdir + "/%s" % model, verbose=sys.stderr)

        cmd_gapc = 'cd %s && gapc -p "alg_inside" %s.gap' % (
            self.fp_tmpdir, model)
        result_gapc = run_cmd(cmd_gapc)
        self.assertEqual(result_gapc, [""])

        cmd_make = 'cd %s && make -f out.mf' % (self.fp_tmpdir)
        result_make = run_cmd(cmd_make)
        self.assertEqual(len(result_make), 7)

        cmd_binary = 'cd %s && ./out %s' % (self.fp_tmpdir, sequence)
        result_binary = run_cmd(cmd_binary)
        obs = result_binary[-1].strip()
        # validated against cmalign-1.1.4 -g --cpu 1 --notrunc --nonbanded --tfile tmp.parsetree RFmicro.cm tmp.fasta
        self.assertAlmostEqual(float(obs), -19.8979)

    def test_model2probdot(self):
        model = parse_cm("RF00005.cm")
        dot = model2probdot(model, None)

        with open("Truth/rf00005_noprob.dot", "r") as f:
            exp = ''.join(f.readlines())
            self.assertEqual(exp, dot)

    def test_patch_report_insideoutside(self):
        fp_input = os.path.join(self.fp_tmpdir, 'rf00005.hh')
        shutil.copyfile("Data/rf00005.hh", fp_input)
        obs = patch_report_insideoutside(fp_input, inplace=False)
        with open("Truth/rf00005_report.hh", "r") as f:
            exp = ''.join(f.readlines())
            self.assertEqual(obs, exp)

    def test_acm2probdot(self):
        obs = acm2probdot('Data/acmsearch_RF00005.gap', probs=None)

        with open("Truth/acm00005.dot", "r") as f:
            exp = ''.join(f.readlines())
            self.assertEqual(obs, exp)

if __name__ == '__main__':
    main()
