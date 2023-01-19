#!/usr/bin/env python
# coding: utf-8
import subprocess
import sys
import tempfile
import shutil
import os

from unittest import TestCase, main

sys.path.append("../")
from cm import (cm2gapc, model2probs, model2grammar, parse_cm)
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

if __name__ == '__main__':
    main()
