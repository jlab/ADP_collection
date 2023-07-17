    double res_full = nt_state_S_0(t_0_left_most, t_0_right_most);
    double res_empty = nt_outside_state_S_0(t_0_left_most, t_0_right_most);
    double res_inside;
    double res_outside;

    List_Ref<double> answers_state_D_100;
    double eval_state_D_100;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_100(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_100(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_100, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_100 = pow(2, h(answers_state_D_100));
    out << "state_D_100: " << eval_state_D_100 << "\n";

    List_Ref<double> answers_state_D_103;
    double eval_state_D_103;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_103(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_103(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_103, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_103 = pow(2, h(answers_state_D_103));
    out << "state_D_103: " << eval_state_D_103 << "\n";

    List_Ref<double> answers_state_D_106;
    double eval_state_D_106;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_106(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_106(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_106, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_106 = pow(2, h(answers_state_D_106));
    out << "state_D_106: " << eval_state_D_106 << "\n";

    List_Ref<double> answers_state_D_109;
    double eval_state_D_109;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_109(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_109(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_109, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_109 = pow(2, h(answers_state_D_109));
    out << "state_D_109: " << eval_state_D_109 << "\n";

    List_Ref<double> answers_state_D_112;
    double eval_state_D_112;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_112(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_112(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_112, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_112 = pow(2, h(answers_state_D_112));
    out << "state_D_112: " << eval_state_D_112 << "\n";

    List_Ref<double> answers_state_D_115;
    double eval_state_D_115;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_115(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_115(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_115, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_115 = pow(2, h(answers_state_D_115));
    out << "state_D_115: " << eval_state_D_115 << "\n";

    List_Ref<double> answers_state_D_118;
    double eval_state_D_118;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_118(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_118(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_118, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_118 = pow(2, h(answers_state_D_118));
    out << "state_D_118: " << eval_state_D_118 << "\n";

    List_Ref<double> answers_state_D_127;
    double eval_state_D_127;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_127(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_127(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_127, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_127 = pow(2, h(answers_state_D_127));
    out << "state_D_127: " << eval_state_D_127 << "\n";

    List_Ref<double> answers_state_D_133;
    double eval_state_D_133;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_133(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_133(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_133, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_133 = pow(2, h(answers_state_D_133));
    out << "state_D_133: " << eval_state_D_133 << "\n";

    List_Ref<double> answers_state_D_139;
    double eval_state_D_139;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_139(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_139(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_139, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_139 = pow(2, h(answers_state_D_139));
    out << "state_D_139: " << eval_state_D_139 << "\n";

    List_Ref<double> answers_state_D_145;
    double eval_state_D_145;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_145(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_145(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_145, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_145 = pow(2, h(answers_state_D_145));
    out << "state_D_145: " << eval_state_D_145 << "\n";

    List_Ref<double> answers_state_D_149;
    double eval_state_D_149;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_149(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_149(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_149, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_149 = pow(2, h(answers_state_D_149));
    out << "state_D_149: " << eval_state_D_149 << "\n";

    List_Ref<double> answers_state_D_15;
    double eval_state_D_15;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_15(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_15(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_15, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_15 = pow(2, h(answers_state_D_15));
    out << "state_D_15: " << eval_state_D_15 << "\n";

    List_Ref<double> answers_state_D_152;
    double eval_state_D_152;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_152(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_152(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_152, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_152 = pow(2, h(answers_state_D_152));
    out << "state_D_152: " << eval_state_D_152 << "\n";

    List_Ref<double> answers_state_D_155;
    double eval_state_D_155;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_155(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_155(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_155, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_155 = pow(2, h(answers_state_D_155));
    out << "state_D_155: " << eval_state_D_155 << "\n";

    List_Ref<double> answers_state_D_158;
    double eval_state_D_158;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_158(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_158(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_158, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_158 = pow(2, h(answers_state_D_158));
    out << "state_D_158: " << eval_state_D_158 << "\n";

    List_Ref<double> answers_state_D_161;
    double eval_state_D_161;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_161(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_161(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_161, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_161 = pow(2, h(answers_state_D_161));
    out << "state_D_161: " << eval_state_D_161 << "\n";

    List_Ref<double> answers_state_D_164;
    double eval_state_D_164;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_164(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_164(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_164, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_164 = pow(2, h(answers_state_D_164));
    out << "state_D_164: " << eval_state_D_164 << "\n";

    List_Ref<double> answers_state_D_167;
    double eval_state_D_167;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_167(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_167(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_167, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_167 = pow(2, h(answers_state_D_167));
    out << "state_D_167: " << eval_state_D_167 << "\n";

    List_Ref<double> answers_state_D_173;
    double eval_state_D_173;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_173(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_173(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_173, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_173 = pow(2, h(answers_state_D_173));
    out << "state_D_173: " << eval_state_D_173 << "\n";

    List_Ref<double> answers_state_D_178;
    double eval_state_D_178;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_178(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_178(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_178, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_178 = pow(2, h(answers_state_D_178));
    out << "state_D_178: " << eval_state_D_178 << "\n";

    List_Ref<double> answers_state_D_184;
    double eval_state_D_184;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_184(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_184(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_184, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_184 = pow(2, h(answers_state_D_184));
    out << "state_D_184: " << eval_state_D_184 << "\n";

    List_Ref<double> answers_state_D_190;
    double eval_state_D_190;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_190(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_190(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_190, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_190 = pow(2, h(answers_state_D_190));
    out << "state_D_190: " << eval_state_D_190 << "\n";

    List_Ref<double> answers_state_D_196;
    double eval_state_D_196;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_196(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_196(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_196, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_196 = pow(2, h(answers_state_D_196));
    out << "state_D_196: " << eval_state_D_196 << "\n";

    List_Ref<double> answers_state_D_202;
    double eval_state_D_202;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_202(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_202(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_202, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_202 = pow(2, h(answers_state_D_202));
    out << "state_D_202: " << eval_state_D_202 << "\n";

    List_Ref<double> answers_state_D_206;
    double eval_state_D_206;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_206(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_206(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_206, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_206 = pow(2, h(answers_state_D_206));
    out << "state_D_206: " << eval_state_D_206 << "\n";

    List_Ref<double> answers_state_D_209;
    double eval_state_D_209;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_209(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_209(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_209, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_209 = pow(2, h(answers_state_D_209));
    out << "state_D_209: " << eval_state_D_209 << "\n";

    List_Ref<double> answers_state_D_21;
    double eval_state_D_21;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_21(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_21(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_21, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_21 = pow(2, h(answers_state_D_21));
    out << "state_D_21: " << eval_state_D_21 << "\n";

    List_Ref<double> answers_state_D_212;
    double eval_state_D_212;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_212(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_212(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_212, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_212 = pow(2, h(answers_state_D_212));
    out << "state_D_212: " << eval_state_D_212 << "\n";

    List_Ref<double> answers_state_D_215;
    double eval_state_D_215;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_215(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_215(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_215, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_215 = pow(2, h(answers_state_D_215));
    out << "state_D_215: " << eval_state_D_215 << "\n";

    List_Ref<double> answers_state_D_218;
    double eval_state_D_218;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_218(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_218(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_218, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_218 = pow(2, h(answers_state_D_218));
    out << "state_D_218: " << eval_state_D_218 << "\n";

    List_Ref<double> answers_state_D_221;
    double eval_state_D_221;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_221(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_221(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_221, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_221 = pow(2, h(answers_state_D_221));
    out << "state_D_221: " << eval_state_D_221 << "\n";

    List_Ref<double> answers_state_D_224;
    double eval_state_D_224;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_224(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_224(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_224, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_224 = pow(2, h(answers_state_D_224));
    out << "state_D_224: " << eval_state_D_224 << "\n";

    List_Ref<double> answers_state_D_27;
    double eval_state_D_27;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_27(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_27(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_27, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_27 = pow(2, h(answers_state_D_27));
    out << "state_D_27: " << eval_state_D_27 << "\n";

    List_Ref<double> answers_state_D_33;
    double eval_state_D_33;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_33(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_33(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_33, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_33 = pow(2, h(answers_state_D_33));
    out << "state_D_33: " << eval_state_D_33 << "\n";

    List_Ref<double> answers_state_D_39;
    double eval_state_D_39;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_39(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_39(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_39, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_39 = pow(2, h(answers_state_D_39));
    out << "state_D_39: " << eval_state_D_39 << "\n";

    List_Ref<double> answers_state_D_4;
    double eval_state_D_4;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_4(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_4(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_4, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_4 = pow(2, h(answers_state_D_4));
    out << "state_D_4: " << eval_state_D_4 << "\n";

    List_Ref<double> answers_state_D_45;
    double eval_state_D_45;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_45(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_45(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_45, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_45 = pow(2, h(answers_state_D_45));
    out << "state_D_45: " << eval_state_D_45 << "\n";

    List_Ref<double> answers_state_D_49;
    double eval_state_D_49;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_49(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_49(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_49, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_49 = pow(2, h(answers_state_D_49));
    out << "state_D_49: " << eval_state_D_49 << "\n";

    List_Ref<double> answers_state_D_52;
    double eval_state_D_52;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_52(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_52(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_52, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_52 = pow(2, h(answers_state_D_52));
    out << "state_D_52: " << eval_state_D_52 << "\n";

    List_Ref<double> answers_state_D_58;
    double eval_state_D_58;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_58(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_58(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_58, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_58 = pow(2, h(answers_state_D_58));
    out << "state_D_58: " << eval_state_D_58 << "\n";

    List_Ref<double> answers_state_D_61;
    double eval_state_D_61;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_61(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_61(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_61, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_61 = pow(2, h(answers_state_D_61));
    out << "state_D_61: " << eval_state_D_61 << "\n";

    List_Ref<double> answers_state_D_64;
    double eval_state_D_64;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_64(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_64(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_64, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_64 = pow(2, h(answers_state_D_64));
    out << "state_D_64: " << eval_state_D_64 << "\n";

    List_Ref<double> answers_state_D_67;
    double eval_state_D_67;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_67(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_67(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_67, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_67 = pow(2, h(answers_state_D_67));
    out << "state_D_67: " << eval_state_D_67 << "\n";

    List_Ref<double> answers_state_D_72;
    double eval_state_D_72;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_72(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_72(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_72, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_72 = pow(2, h(answers_state_D_72));
    out << "state_D_72: " << eval_state_D_72 << "\n";

    List_Ref<double> answers_state_D_78;
    double eval_state_D_78;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_78(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_78(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_78, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_78 = pow(2, h(answers_state_D_78));
    out << "state_D_78: " << eval_state_D_78 << "\n";

    List_Ref<double> answers_state_D_84;
    double eval_state_D_84;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_84(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_84(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_84, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_84 = pow(2, h(answers_state_D_84));
    out << "state_D_84: " << eval_state_D_84 << "\n";

    List_Ref<double> answers_state_D_9;
    double eval_state_D_9;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_9(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_9(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_9, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_9 = pow(2, h(answers_state_D_9));
    out << "state_D_9: " << eval_state_D_9 << "\n";

    List_Ref<double> answers_state_D_90;
    double eval_state_D_90;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_90(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_90(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_90, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_90 = pow(2, h(answers_state_D_90));
    out << "state_D_90: " << eval_state_D_90 << "\n";

    List_Ref<double> answers_state_D_96;
    double eval_state_D_96;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_D_96(t_0_i, t_0_j);
        res_outside = nt_outside_state_D_96(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_D_96, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_D_96 = pow(2, h(answers_state_D_96));
    out << "state_D_96: " << eval_state_D_96 << "\n";

    List_Ref<double> answers_state_IL_1;
    double eval_state_IL_1;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      res_inside = nt_state_IL_1(t_0_i, t_0_right_most);
      res_outside = nt_outside_state_IL_1(t_0_i, t_0_right_most);
      if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
        push_back(answers_state_IL_1, (res_inside + res_outside - res_full - res_empty));
      }
    }
    eval_state_IL_1 = pow(2, h(answers_state_IL_1));
    out << "state_IL_1: " << eval_state_IL_1 << "\n";

    List_Ref<double> answers_state_IL_10;
    double eval_state_IL_10;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_10(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_10(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_10, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_10 = pow(2, h(answers_state_IL_10));
    out << "state_IL_10: " << eval_state_IL_10 << "\n";

    List_Ref<double> answers_state_IL_101;
    double eval_state_IL_101;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_101(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_101(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_101, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_101 = pow(2, h(answers_state_IL_101));
    out << "state_IL_101: " << eval_state_IL_101 << "\n";

    List_Ref<double> answers_state_IL_104;
    double eval_state_IL_104;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_104(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_104(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_104, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_104 = pow(2, h(answers_state_IL_104));
    out << "state_IL_104: " << eval_state_IL_104 << "\n";

    List_Ref<double> answers_state_IL_107;
    double eval_state_IL_107;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_107(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_107(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_107, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_107 = pow(2, h(answers_state_IL_107));
    out << "state_IL_107: " << eval_state_IL_107 << "\n";

    List_Ref<double> answers_state_IL_110;
    double eval_state_IL_110;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_110(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_110(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_110, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_110 = pow(2, h(answers_state_IL_110));
    out << "state_IL_110: " << eval_state_IL_110 << "\n";

    List_Ref<double> answers_state_IL_113;
    double eval_state_IL_113;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_113(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_113(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_113, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_113 = pow(2, h(answers_state_IL_113));
    out << "state_IL_113: " << eval_state_IL_113 << "\n";

    List_Ref<double> answers_state_IL_116;
    double eval_state_IL_116;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_116(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_116(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_116, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_116 = pow(2, h(answers_state_IL_116));
    out << "state_IL_116: " << eval_state_IL_116 << "\n";

    List_Ref<double> answers_state_IL_128;
    double eval_state_IL_128;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_128(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_128(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_128, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_128 = pow(2, h(answers_state_IL_128));
    out << "state_IL_128: " << eval_state_IL_128 << "\n";

    List_Ref<double> answers_state_IL_134;
    double eval_state_IL_134;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_134(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_134(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_134, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_134 = pow(2, h(answers_state_IL_134));
    out << "state_IL_134: " << eval_state_IL_134 << "\n";

    List_Ref<double> answers_state_IL_140;
    double eval_state_IL_140;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_140(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_140(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_140, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_140 = pow(2, h(answers_state_IL_140));
    out << "state_IL_140: " << eval_state_IL_140 << "\n";

    List_Ref<double> answers_state_IL_146;
    double eval_state_IL_146;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_146(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_146(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_146, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_146 = pow(2, h(answers_state_IL_146));
    out << "state_IL_146: " << eval_state_IL_146 << "\n";

    List_Ref<double> answers_state_IL_150;
    double eval_state_IL_150;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_150(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_150(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_150, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_150 = pow(2, h(answers_state_IL_150));
    out << "state_IL_150: " << eval_state_IL_150 << "\n";

    List_Ref<double> answers_state_IL_153;
    double eval_state_IL_153;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_153(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_153(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_153, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_153 = pow(2, h(answers_state_IL_153));
    out << "state_IL_153: " << eval_state_IL_153 << "\n";

    List_Ref<double> answers_state_IL_156;
    double eval_state_IL_156;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_156(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_156(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_156, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_156 = pow(2, h(answers_state_IL_156));
    out << "state_IL_156: " << eval_state_IL_156 << "\n";

    List_Ref<double> answers_state_IL_159;
    double eval_state_IL_159;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_159(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_159(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_159, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_159 = pow(2, h(answers_state_IL_159));
    out << "state_IL_159: " << eval_state_IL_159 << "\n";

    List_Ref<double> answers_state_IL_16;
    double eval_state_IL_16;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_16(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_16(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_16, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_16 = pow(2, h(answers_state_IL_16));
    out << "state_IL_16: " << eval_state_IL_16 << "\n";

    List_Ref<double> answers_state_IL_162;
    double eval_state_IL_162;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_162(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_162(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_162, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_162 = pow(2, h(answers_state_IL_162));
    out << "state_IL_162: " << eval_state_IL_162 << "\n";

    List_Ref<double> answers_state_IL_165;
    double eval_state_IL_165;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_165(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_165(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_165, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_165 = pow(2, h(answers_state_IL_165));
    out << "state_IL_165: " << eval_state_IL_165 << "\n";

    List_Ref<double> answers_state_IL_171;
    double eval_state_IL_171;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_171(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_171(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_171, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_171 = pow(2, h(answers_state_IL_171));
    out << "state_IL_171: " << eval_state_IL_171 << "\n";

    List_Ref<double> answers_state_IL_174;
    double eval_state_IL_174;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_174(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_174(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_174, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_174 = pow(2, h(answers_state_IL_174));
    out << "state_IL_174: " << eval_state_IL_174 << "\n";

    List_Ref<double> answers_state_IL_179;
    double eval_state_IL_179;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_179(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_179(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_179, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_179 = pow(2, h(answers_state_IL_179));
    out << "state_IL_179: " << eval_state_IL_179 << "\n";

    List_Ref<double> answers_state_IL_185;
    double eval_state_IL_185;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_185(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_185(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_185, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_185 = pow(2, h(answers_state_IL_185));
    out << "state_IL_185: " << eval_state_IL_185 << "\n";

    List_Ref<double> answers_state_IL_191;
    double eval_state_IL_191;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_191(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_191(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_191, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_191 = pow(2, h(answers_state_IL_191));
    out << "state_IL_191: " << eval_state_IL_191 << "\n";

    List_Ref<double> answers_state_IL_197;
    double eval_state_IL_197;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_197(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_197(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_197, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_197 = pow(2, h(answers_state_IL_197));
    out << "state_IL_197: " << eval_state_IL_197 << "\n";

    List_Ref<double> answers_state_IL_203;
    double eval_state_IL_203;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_203(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_203(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_203, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_203 = pow(2, h(answers_state_IL_203));
    out << "state_IL_203: " << eval_state_IL_203 << "\n";

    List_Ref<double> answers_state_IL_207;
    double eval_state_IL_207;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_207(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_207(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_207, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_207 = pow(2, h(answers_state_IL_207));
    out << "state_IL_207: " << eval_state_IL_207 << "\n";

    List_Ref<double> answers_state_IL_210;
    double eval_state_IL_210;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_210(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_210(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_210, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_210 = pow(2, h(answers_state_IL_210));
    out << "state_IL_210: " << eval_state_IL_210 << "\n";

    List_Ref<double> answers_state_IL_213;
    double eval_state_IL_213;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_213(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_213(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_213, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_213 = pow(2, h(answers_state_IL_213));
    out << "state_IL_213: " << eval_state_IL_213 << "\n";

    List_Ref<double> answers_state_IL_216;
    double eval_state_IL_216;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_216(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_216(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_216, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_216 = pow(2, h(answers_state_IL_216));
    out << "state_IL_216: " << eval_state_IL_216 << "\n";

    List_Ref<double> answers_state_IL_219;
    double eval_state_IL_219;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_219(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_219(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_219, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_219 = pow(2, h(answers_state_IL_219));
    out << "state_IL_219: " << eval_state_IL_219 << "\n";

    List_Ref<double> answers_state_IL_22;
    double eval_state_IL_22;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_22(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_22(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_22, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_22 = pow(2, h(answers_state_IL_22));
    out << "state_IL_22: " << eval_state_IL_22 << "\n";

    List_Ref<double> answers_state_IL_222;
    double eval_state_IL_222;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_222(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_222(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_222, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_222 = pow(2, h(answers_state_IL_222));
    out << "state_IL_222: " << eval_state_IL_222 << "\n";

    List_Ref<double> answers_state_IL_28;
    double eval_state_IL_28;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_28(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_28(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_28, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_28 = pow(2, h(answers_state_IL_28));
    out << "state_IL_28: " << eval_state_IL_28 << "\n";

    List_Ref<double> answers_state_IL_34;
    double eval_state_IL_34;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_34(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_34(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_34, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_34 = pow(2, h(answers_state_IL_34));
    out << "state_IL_34: " << eval_state_IL_34 << "\n";

    List_Ref<double> answers_state_IL_40;
    double eval_state_IL_40;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_40(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_40(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_40, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_40 = pow(2, h(answers_state_IL_40));
    out << "state_IL_40: " << eval_state_IL_40 << "\n";

    List_Ref<double> answers_state_IL_46;
    double eval_state_IL_46;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_46(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_46(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_46, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_46 = pow(2, h(answers_state_IL_46));
    out << "state_IL_46: " << eval_state_IL_46 << "\n";

    List_Ref<double> answers_state_IL_50;
    double eval_state_IL_50;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_50(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_50(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_50, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_50 = pow(2, h(answers_state_IL_50));
    out << "state_IL_50: " << eval_state_IL_50 << "\n";

    List_Ref<double> answers_state_IL_53;
    double eval_state_IL_53;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_53(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_53(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_53, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_53 = pow(2, h(answers_state_IL_53));
    out << "state_IL_53: " << eval_state_IL_53 << "\n";

    List_Ref<double> answers_state_IL_56;
    double eval_state_IL_56;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_56(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_56(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_56, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_56 = pow(2, h(answers_state_IL_56));
    out << "state_IL_56: " << eval_state_IL_56 << "\n";

    List_Ref<double> answers_state_IL_59;
    double eval_state_IL_59;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_59(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_59(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_59, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_59 = pow(2, h(answers_state_IL_59));
    out << "state_IL_59: " << eval_state_IL_59 << "\n";

    List_Ref<double> answers_state_IL_62;
    double eval_state_IL_62;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_62(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_62(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_62, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_62 = pow(2, h(answers_state_IL_62));
    out << "state_IL_62: " << eval_state_IL_62 << "\n";

    List_Ref<double> answers_state_IL_65;
    double eval_state_IL_65;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_65(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_65(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_65, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_65 = pow(2, h(answers_state_IL_65));
    out << "state_IL_65: " << eval_state_IL_65 << "\n";

    List_Ref<double> answers_state_IL_68;
    double eval_state_IL_68;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_68(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_68(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_68, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_68 = pow(2, h(answers_state_IL_68));
    out << "state_IL_68: " << eval_state_IL_68 << "\n";

    List_Ref<double> answers_state_IL_73;
    double eval_state_IL_73;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_73(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_73(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_73, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_73 = pow(2, h(answers_state_IL_73));
    out << "state_IL_73: " << eval_state_IL_73 << "\n";

    List_Ref<double> answers_state_IL_79;
    double eval_state_IL_79;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_79(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_79(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_79, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_79 = pow(2, h(answers_state_IL_79));
    out << "state_IL_79: " << eval_state_IL_79 << "\n";

    List_Ref<double> answers_state_IL_85;
    double eval_state_IL_85;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_85(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_85(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_85, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_85 = pow(2, h(answers_state_IL_85));
    out << "state_IL_85: " << eval_state_IL_85 << "\n";

    List_Ref<double> answers_state_IL_91;
    double eval_state_IL_91;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_91(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_91(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_91, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_91 = pow(2, h(answers_state_IL_91));
    out << "state_IL_91: " << eval_state_IL_91 << "\n";

    List_Ref<double> answers_state_IL_97;
    double eval_state_IL_97;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IL_97(t_0_i, t_0_j);
        res_outside = nt_outside_state_IL_97(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IL_97, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IL_97 = pow(2, h(answers_state_IL_97));
    out << "state_IL_97: " << eval_state_IL_97 << "\n";

    List_Ref<double> answers_state_IR_11;
    double eval_state_IR_11;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_11(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_11(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_11, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_11 = pow(2, h(answers_state_IR_11));
    out << "state_IR_11: " << eval_state_IR_11 << "\n";

    List_Ref<double> answers_state_IR_129;
    double eval_state_IR_129;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_129(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_129(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_129, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_129 = pow(2, h(answers_state_IR_129));
    out << "state_IR_129: " << eval_state_IR_129 << "\n";

    List_Ref<double> answers_state_IR_135;
    double eval_state_IR_135;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_135(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_135(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_135, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_135 = pow(2, h(answers_state_IR_135));
    out << "state_IR_135: " << eval_state_IR_135 << "\n";

    List_Ref<double> answers_state_IR_141;
    double eval_state_IR_141;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_141(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_141(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_141, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_141 = pow(2, h(answers_state_IR_141));
    out << "state_IR_141: " << eval_state_IR_141 << "\n";

    List_Ref<double> answers_state_IR_147;
    double eval_state_IR_147;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_147(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_147(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_147, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_147 = pow(2, h(answers_state_IR_147));
    out << "state_IR_147: " << eval_state_IR_147 << "\n";

    List_Ref<double> answers_state_IR_17;
    double eval_state_IR_17;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_17(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_17(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_17, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_17 = pow(2, h(answers_state_IR_17));
    out << "state_IR_17: " << eval_state_IR_17 << "\n";

    List_Ref<double> answers_state_IR_180;
    double eval_state_IR_180;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_180(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_180(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_180, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_180 = pow(2, h(answers_state_IR_180));
    out << "state_IR_180: " << eval_state_IR_180 << "\n";

    List_Ref<double> answers_state_IR_186;
    double eval_state_IR_186;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_186(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_186(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_186, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_186 = pow(2, h(answers_state_IR_186));
    out << "state_IR_186: " << eval_state_IR_186 << "\n";

    List_Ref<double> answers_state_IR_192;
    double eval_state_IR_192;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_192(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_192(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_192, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_192 = pow(2, h(answers_state_IR_192));
    out << "state_IR_192: " << eval_state_IR_192 << "\n";

    List_Ref<double> answers_state_IR_198;
    double eval_state_IR_198;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_198(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_198(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_198, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_198 = pow(2, h(answers_state_IR_198));
    out << "state_IR_198: " << eval_state_IR_198 << "\n";

    List_Ref<double> answers_state_IR_2;
    double eval_state_IR_2;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_2(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_2(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_2, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_2 = pow(2, h(answers_state_IR_2));
    out << "state_IR_2: " << eval_state_IR_2 << "\n";

    List_Ref<double> answers_state_IR_204;
    double eval_state_IR_204;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_204(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_204(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_204, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_204 = pow(2, h(answers_state_IR_204));
    out << "state_IR_204: " << eval_state_IR_204 << "\n";

    List_Ref<double> answers_state_IR_23;
    double eval_state_IR_23;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_23(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_23(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_23, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_23 = pow(2, h(answers_state_IR_23));
    out << "state_IR_23: " << eval_state_IR_23 << "\n";

    List_Ref<double> answers_state_IR_29;
    double eval_state_IR_29;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_29(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_29(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_29, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_29 = pow(2, h(answers_state_IR_29));
    out << "state_IR_29: " << eval_state_IR_29 << "\n";

    List_Ref<double> answers_state_IR_35;
    double eval_state_IR_35;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_35(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_35(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_35, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_35 = pow(2, h(answers_state_IR_35));
    out << "state_IR_35: " << eval_state_IR_35 << "\n";

    List_Ref<double> answers_state_IR_41;
    double eval_state_IR_41;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_41(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_41(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_41, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_41 = pow(2, h(answers_state_IR_41));
    out << "state_IR_41: " << eval_state_IR_41 << "\n";

    List_Ref<double> answers_state_IR_47;
    double eval_state_IR_47;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_47(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_47(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_47, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_47 = pow(2, h(answers_state_IR_47));
    out << "state_IR_47: " << eval_state_IR_47 << "\n";

    List_Ref<double> answers_state_IR_5;
    double eval_state_IR_5;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_5(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_5(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_5, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_5 = pow(2, h(answers_state_IR_5));
    out << "state_IR_5: " << eval_state_IR_5 << "\n";

    List_Ref<double> answers_state_IR_74;
    double eval_state_IR_74;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_74(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_74(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_74, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_74 = pow(2, h(answers_state_IR_74));
    out << "state_IR_74: " << eval_state_IR_74 << "\n";

    List_Ref<double> answers_state_IR_80;
    double eval_state_IR_80;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_80(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_80(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_80, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_80 = pow(2, h(answers_state_IR_80));
    out << "state_IR_80: " << eval_state_IR_80 << "\n";

    List_Ref<double> answers_state_IR_86;
    double eval_state_IR_86;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_86(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_86(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_86, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_86 = pow(2, h(answers_state_IR_86));
    out << "state_IR_86: " << eval_state_IR_86 << "\n";

    List_Ref<double> answers_state_IR_92;
    double eval_state_IR_92;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_92(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_92(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_92, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_92 = pow(2, h(answers_state_IR_92));
    out << "state_IR_92: " << eval_state_IR_92 << "\n";

    List_Ref<double> answers_state_IR_98;
    double eval_state_IR_98;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_IR_98(t_0_i, t_0_j);
        res_outside = nt_outside_state_IR_98(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_IR_98, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_IR_98 = pow(2, h(answers_state_IR_98));
    out << "state_IR_98: " << eval_state_IR_98 << "\n";

    List_Ref<double> answers_state_ML_102;
    double eval_state_ML_102;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_102(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_102(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_102, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_102 = pow(2, h(answers_state_ML_102));
    out << "state_ML_102: " << eval_state_ML_102 << "\n";

    List_Ref<double> answers_state_ML_105;
    double eval_state_ML_105;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_105(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_105(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_105, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_105 = pow(2, h(answers_state_ML_105));
    out << "state_ML_105: " << eval_state_ML_105 << "\n";

    List_Ref<double> answers_state_ML_108;
    double eval_state_ML_108;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_108(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_108(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_108, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_108 = pow(2, h(answers_state_ML_108));
    out << "state_ML_108: " << eval_state_ML_108 << "\n";

    List_Ref<double> answers_state_ML_111;
    double eval_state_ML_111;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_111(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_111(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_111, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_111 = pow(2, h(answers_state_ML_111));
    out << "state_ML_111: " << eval_state_ML_111 << "\n";

    List_Ref<double> answers_state_ML_114;
    double eval_state_ML_114;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_114(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_114(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_114, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_114 = pow(2, h(answers_state_ML_114));
    out << "state_ML_114: " << eval_state_ML_114 << "\n";

    List_Ref<double> answers_state_ML_117;
    double eval_state_ML_117;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_117(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_117(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_117, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_117 = pow(2, h(answers_state_ML_117));
    out << "state_ML_117: " << eval_state_ML_117 << "\n";

    List_Ref<double> answers_state_ML_125;
    double eval_state_ML_125;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_125(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_125(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_125, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_125 = pow(2, h(answers_state_ML_125));
    out << "state_ML_125: " << eval_state_ML_125 << "\n";

    List_Ref<double> answers_state_ML_13;
    double eval_state_ML_13;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_13(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_13(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_13, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_13 = pow(2, h(answers_state_ML_13));
    out << "state_ML_13: " << eval_state_ML_13 << "\n";

    List_Ref<double> answers_state_ML_131;
    double eval_state_ML_131;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_131(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_131(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_131, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_131 = pow(2, h(answers_state_ML_131));
    out << "state_ML_131: " << eval_state_ML_131 << "\n";

    List_Ref<double> answers_state_ML_137;
    double eval_state_ML_137;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_137(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_137(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_137, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_137 = pow(2, h(answers_state_ML_137));
    out << "state_ML_137: " << eval_state_ML_137 << "\n";

    List_Ref<double> answers_state_ML_143;
    double eval_state_ML_143;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_143(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_143(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_143, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_143 = pow(2, h(answers_state_ML_143));
    out << "state_ML_143: " << eval_state_ML_143 << "\n";

    List_Ref<double> answers_state_ML_148;
    double eval_state_ML_148;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_148(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_148(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_148, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_148 = pow(2, h(answers_state_ML_148));
    out << "state_ML_148: " << eval_state_ML_148 << "\n";

    List_Ref<double> answers_state_ML_151;
    double eval_state_ML_151;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_151(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_151(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_151, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_151 = pow(2, h(answers_state_ML_151));
    out << "state_ML_151: " << eval_state_ML_151 << "\n";

    List_Ref<double> answers_state_ML_154;
    double eval_state_ML_154;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_154(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_154(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_154, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_154 = pow(2, h(answers_state_ML_154));
    out << "state_ML_154: " << eval_state_ML_154 << "\n";

    List_Ref<double> answers_state_ML_157;
    double eval_state_ML_157;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_157(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_157(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_157, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_157 = pow(2, h(answers_state_ML_157));
    out << "state_ML_157: " << eval_state_ML_157 << "\n";

    List_Ref<double> answers_state_ML_160;
    double eval_state_ML_160;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_160(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_160(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_160, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_160 = pow(2, h(answers_state_ML_160));
    out << "state_ML_160: " << eval_state_ML_160 << "\n";

    List_Ref<double> answers_state_ML_163;
    double eval_state_ML_163;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_163(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_163(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_163, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_163 = pow(2, h(answers_state_ML_163));
    out << "state_ML_163: " << eval_state_ML_163 << "\n";

    List_Ref<double> answers_state_ML_166;
    double eval_state_ML_166;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_166(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_166(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_166, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_166 = pow(2, h(answers_state_ML_166));
    out << "state_ML_166: " << eval_state_ML_166 << "\n";

    List_Ref<double> answers_state_ML_172;
    double eval_state_ML_172;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_172(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_172(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_172, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_172 = pow(2, h(answers_state_ML_172));
    out << "state_ML_172: " << eval_state_ML_172 << "\n";

    List_Ref<double> answers_state_ML_176;
    double eval_state_ML_176;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_176(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_176(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_176, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_176 = pow(2, h(answers_state_ML_176));
    out << "state_ML_176: " << eval_state_ML_176 << "\n";

    List_Ref<double> answers_state_ML_182;
    double eval_state_ML_182;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_182(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_182(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_182, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_182 = pow(2, h(answers_state_ML_182));
    out << "state_ML_182: " << eval_state_ML_182 << "\n";

    List_Ref<double> answers_state_ML_188;
    double eval_state_ML_188;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_188(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_188(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_188, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_188 = pow(2, h(answers_state_ML_188));
    out << "state_ML_188: " << eval_state_ML_188 << "\n";

    List_Ref<double> answers_state_ML_19;
    double eval_state_ML_19;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_19(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_19(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_19, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_19 = pow(2, h(answers_state_ML_19));
    out << "state_ML_19: " << eval_state_ML_19 << "\n";

    List_Ref<double> answers_state_ML_194;
    double eval_state_ML_194;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_194(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_194(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_194, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_194 = pow(2, h(answers_state_ML_194));
    out << "state_ML_194: " << eval_state_ML_194 << "\n";

    List_Ref<double> answers_state_ML_200;
    double eval_state_ML_200;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_200(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_200(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_200, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_200 = pow(2, h(answers_state_ML_200));
    out << "state_ML_200: " << eval_state_ML_200 << "\n";

    List_Ref<double> answers_state_ML_205;
    double eval_state_ML_205;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_205(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_205(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_205, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_205 = pow(2, h(answers_state_ML_205));
    out << "state_ML_205: " << eval_state_ML_205 << "\n";

    List_Ref<double> answers_state_ML_208;
    double eval_state_ML_208;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_208(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_208(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_208, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_208 = pow(2, h(answers_state_ML_208));
    out << "state_ML_208: " << eval_state_ML_208 << "\n";

    List_Ref<double> answers_state_ML_211;
    double eval_state_ML_211;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_211(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_211(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_211, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_211 = pow(2, h(answers_state_ML_211));
    out << "state_ML_211: " << eval_state_ML_211 << "\n";

    List_Ref<double> answers_state_ML_214;
    double eval_state_ML_214;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_214(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_214(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_214, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_214 = pow(2, h(answers_state_ML_214));
    out << "state_ML_214: " << eval_state_ML_214 << "\n";

    List_Ref<double> answers_state_ML_217;
    double eval_state_ML_217;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_217(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_217(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_217, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_217 = pow(2, h(answers_state_ML_217));
    out << "state_ML_217: " << eval_state_ML_217 << "\n";

    List_Ref<double> answers_state_ML_220;
    double eval_state_ML_220;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_220(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_220(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_220, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_220 = pow(2, h(answers_state_ML_220));
    out << "state_ML_220: " << eval_state_ML_220 << "\n";

    List_Ref<double> answers_state_ML_223;
    double eval_state_ML_223;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_223(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_223(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_223, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_223 = pow(2, h(answers_state_ML_223));
    out << "state_ML_223: " << eval_state_ML_223 << "\n";

    List_Ref<double> answers_state_ML_25;
    double eval_state_ML_25;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_25(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_25(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_25, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_25 = pow(2, h(answers_state_ML_25));
    out << "state_ML_25: " << eval_state_ML_25 << "\n";

    List_Ref<double> answers_state_ML_31;
    double eval_state_ML_31;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_31(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_31(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_31, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_31 = pow(2, h(answers_state_ML_31));
    out << "state_ML_31: " << eval_state_ML_31 << "\n";

    List_Ref<double> answers_state_ML_37;
    double eval_state_ML_37;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_37(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_37(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_37, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_37 = pow(2, h(answers_state_ML_37));
    out << "state_ML_37: " << eval_state_ML_37 << "\n";

    List_Ref<double> answers_state_ML_43;
    double eval_state_ML_43;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_43(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_43(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_43, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_43 = pow(2, h(answers_state_ML_43));
    out << "state_ML_43: " << eval_state_ML_43 << "\n";

    List_Ref<double> answers_state_ML_48;
    double eval_state_ML_48;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_48(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_48(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_48, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_48 = pow(2, h(answers_state_ML_48));
    out << "state_ML_48: " << eval_state_ML_48 << "\n";

    List_Ref<double> answers_state_ML_51;
    double eval_state_ML_51;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_51(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_51(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_51, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_51 = pow(2, h(answers_state_ML_51));
    out << "state_ML_51: " << eval_state_ML_51 << "\n";

    List_Ref<double> answers_state_ML_57;
    double eval_state_ML_57;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_57(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_57(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_57, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_57 = pow(2, h(answers_state_ML_57));
    out << "state_ML_57: " << eval_state_ML_57 << "\n";

    List_Ref<double> answers_state_ML_60;
    double eval_state_ML_60;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_60(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_60(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_60, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_60 = pow(2, h(answers_state_ML_60));
    out << "state_ML_60: " << eval_state_ML_60 << "\n";

    List_Ref<double> answers_state_ML_63;
    double eval_state_ML_63;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_63(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_63(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_63, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_63 = pow(2, h(answers_state_ML_63));
    out << "state_ML_63: " << eval_state_ML_63 << "\n";

    List_Ref<double> answers_state_ML_66;
    double eval_state_ML_66;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_66(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_66(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_66, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_66 = pow(2, h(answers_state_ML_66));
    out << "state_ML_66: " << eval_state_ML_66 << "\n";

    List_Ref<double> answers_state_ML_7;
    double eval_state_ML_7;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_7(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_7(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_7, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_7 = pow(2, h(answers_state_ML_7));
    out << "state_ML_7: " << eval_state_ML_7 << "\n";

    List_Ref<double> answers_state_ML_70;
    double eval_state_ML_70;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_70(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_70(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_70, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_70 = pow(2, h(answers_state_ML_70));
    out << "state_ML_70: " << eval_state_ML_70 << "\n";

    List_Ref<double> answers_state_ML_76;
    double eval_state_ML_76;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_76(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_76(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_76, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_76 = pow(2, h(answers_state_ML_76));
    out << "state_ML_76: " << eval_state_ML_76 << "\n";

    List_Ref<double> answers_state_ML_82;
    double eval_state_ML_82;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_82(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_82(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_82, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_82 = pow(2, h(answers_state_ML_82));
    out << "state_ML_82: " << eval_state_ML_82 << "\n";

    List_Ref<double> answers_state_ML_88;
    double eval_state_ML_88;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_88(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_88(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_88, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_88 = pow(2, h(answers_state_ML_88));
    out << "state_ML_88: " << eval_state_ML_88 << "\n";

    List_Ref<double> answers_state_ML_94;
    double eval_state_ML_94;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_94(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_94(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_94, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_94 = pow(2, h(answers_state_ML_94));
    out << "state_ML_94: " << eval_state_ML_94 << "\n";

    List_Ref<double> answers_state_ML_99;
    double eval_state_ML_99;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_ML_99(t_0_i, t_0_j);
        res_outside = nt_outside_state_ML_99(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_ML_99, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_ML_99 = pow(2, h(answers_state_ML_99));
    out << "state_ML_99: " << eval_state_ML_99 << "\n";

    List_Ref<double> answers_state_MP_12;
    double eval_state_MP_12;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_12(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_12(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_12, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_12 = pow(2, h(answers_state_MP_12));
    out << "state_MP_12: " << eval_state_MP_12 << "\n";

    List_Ref<double> answers_state_MP_124;
    double eval_state_MP_124;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_124(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_124(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_124, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_124 = pow(2, h(answers_state_MP_124));
    out << "state_MP_124: " << eval_state_MP_124 << "\n";

    List_Ref<double> answers_state_MP_130;
    double eval_state_MP_130;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_130(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_130(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_130, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_130 = pow(2, h(answers_state_MP_130));
    out << "state_MP_130: " << eval_state_MP_130 << "\n";

    List_Ref<double> answers_state_MP_136;
    double eval_state_MP_136;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_136(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_136(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_136, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_136 = pow(2, h(answers_state_MP_136));
    out << "state_MP_136: " << eval_state_MP_136 << "\n";

    List_Ref<double> answers_state_MP_142;
    double eval_state_MP_142;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_142(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_142(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_142, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_142 = pow(2, h(answers_state_MP_142));
    out << "state_MP_142: " << eval_state_MP_142 << "\n";

    List_Ref<double> answers_state_MP_175;
    double eval_state_MP_175;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_175(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_175(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_175, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_175 = pow(2, h(answers_state_MP_175));
    out << "state_MP_175: " << eval_state_MP_175 << "\n";

    List_Ref<double> answers_state_MP_18;
    double eval_state_MP_18;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_18(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_18(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_18, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_18 = pow(2, h(answers_state_MP_18));
    out << "state_MP_18: " << eval_state_MP_18 << "\n";

    List_Ref<double> answers_state_MP_181;
    double eval_state_MP_181;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_181(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_181(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_181, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_181 = pow(2, h(answers_state_MP_181));
    out << "state_MP_181: " << eval_state_MP_181 << "\n";

    List_Ref<double> answers_state_MP_187;
    double eval_state_MP_187;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_187(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_187(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_187, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_187 = pow(2, h(answers_state_MP_187));
    out << "state_MP_187: " << eval_state_MP_187 << "\n";

    List_Ref<double> answers_state_MP_193;
    double eval_state_MP_193;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_193(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_193(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_193, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_193 = pow(2, h(answers_state_MP_193));
    out << "state_MP_193: " << eval_state_MP_193 << "\n";

    List_Ref<double> answers_state_MP_199;
    double eval_state_MP_199;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_199(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_199(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_199, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_199 = pow(2, h(answers_state_MP_199));
    out << "state_MP_199: " << eval_state_MP_199 << "\n";

    List_Ref<double> answers_state_MP_24;
    double eval_state_MP_24;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_24(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_24(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_24, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_24 = pow(2, h(answers_state_MP_24));
    out << "state_MP_24: " << eval_state_MP_24 << "\n";

    List_Ref<double> answers_state_MP_30;
    double eval_state_MP_30;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_30(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_30(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_30, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_30 = pow(2, h(answers_state_MP_30));
    out << "state_MP_30: " << eval_state_MP_30 << "\n";

    List_Ref<double> answers_state_MP_36;
    double eval_state_MP_36;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_36(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_36(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_36, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_36 = pow(2, h(answers_state_MP_36));
    out << "state_MP_36: " << eval_state_MP_36 << "\n";

    List_Ref<double> answers_state_MP_42;
    double eval_state_MP_42;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_42(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_42(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_42, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_42 = pow(2, h(answers_state_MP_42));
    out << "state_MP_42: " << eval_state_MP_42 << "\n";

    List_Ref<double> answers_state_MP_6;
    double eval_state_MP_6;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_6(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_6(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_6, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_6 = pow(2, h(answers_state_MP_6));
    out << "state_MP_6: " << eval_state_MP_6 << "\n";

    List_Ref<double> answers_state_MP_69;
    double eval_state_MP_69;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_69(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_69(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_69, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_69 = pow(2, h(answers_state_MP_69));
    out << "state_MP_69: " << eval_state_MP_69 << "\n";

    List_Ref<double> answers_state_MP_75;
    double eval_state_MP_75;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_75(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_75(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_75, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_75 = pow(2, h(answers_state_MP_75));
    out << "state_MP_75: " << eval_state_MP_75 << "\n";

    List_Ref<double> answers_state_MP_81;
    double eval_state_MP_81;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_81(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_81(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_81, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_81 = pow(2, h(answers_state_MP_81));
    out << "state_MP_81: " << eval_state_MP_81 << "\n";

    List_Ref<double> answers_state_MP_87;
    double eval_state_MP_87;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_87(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_87(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_87, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_87 = pow(2, h(answers_state_MP_87));
    out << "state_MP_87: " << eval_state_MP_87 << "\n";

    List_Ref<double> answers_state_MP_93;
    double eval_state_MP_93;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MP_93(t_0_i, t_0_j);
        res_outside = nt_outside_state_MP_93(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MP_93, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MP_93 = pow(2, h(answers_state_MP_93));
    out << "state_MP_93: " << eval_state_MP_93 << "\n";

    List_Ref<double> answers_state_MR_126;
    double eval_state_MR_126;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_126(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_126(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_126, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_126 = pow(2, h(answers_state_MR_126));
    out << "state_MR_126: " << eval_state_MR_126 << "\n";

    List_Ref<double> answers_state_MR_132;
    double eval_state_MR_132;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_132(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_132(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_132, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_132 = pow(2, h(answers_state_MR_132));
    out << "state_MR_132: " << eval_state_MR_132 << "\n";

    List_Ref<double> answers_state_MR_138;
    double eval_state_MR_138;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_138(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_138(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_138, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_138 = pow(2, h(answers_state_MR_138));
    out << "state_MR_138: " << eval_state_MR_138 << "\n";

    List_Ref<double> answers_state_MR_14;
    double eval_state_MR_14;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_14(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_14(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_14, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_14 = pow(2, h(answers_state_MR_14));
    out << "state_MR_14: " << eval_state_MR_14 << "\n";

    List_Ref<double> answers_state_MR_144;
    double eval_state_MR_144;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_144(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_144(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_144, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_144 = pow(2, h(answers_state_MR_144));
    out << "state_MR_144: " << eval_state_MR_144 << "\n";

    List_Ref<double> answers_state_MR_177;
    double eval_state_MR_177;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_177(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_177(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_177, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_177 = pow(2, h(answers_state_MR_177));
    out << "state_MR_177: " << eval_state_MR_177 << "\n";

    List_Ref<double> answers_state_MR_183;
    double eval_state_MR_183;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_183(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_183(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_183, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_183 = pow(2, h(answers_state_MR_183));
    out << "state_MR_183: " << eval_state_MR_183 << "\n";

    List_Ref<double> answers_state_MR_189;
    double eval_state_MR_189;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_189(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_189(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_189, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_189 = pow(2, h(answers_state_MR_189));
    out << "state_MR_189: " << eval_state_MR_189 << "\n";

    List_Ref<double> answers_state_MR_195;
    double eval_state_MR_195;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_195(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_195(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_195, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_195 = pow(2, h(answers_state_MR_195));
    out << "state_MR_195: " << eval_state_MR_195 << "\n";

    List_Ref<double> answers_state_MR_20;
    double eval_state_MR_20;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_20(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_20(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_20, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_20 = pow(2, h(answers_state_MR_20));
    out << "state_MR_20: " << eval_state_MR_20 << "\n";

    List_Ref<double> answers_state_MR_201;
    double eval_state_MR_201;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_201(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_201(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_201, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_201 = pow(2, h(answers_state_MR_201));
    out << "state_MR_201: " << eval_state_MR_201 << "\n";

    List_Ref<double> answers_state_MR_26;
    double eval_state_MR_26;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_26(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_26(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_26, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_26 = pow(2, h(answers_state_MR_26));
    out << "state_MR_26: " << eval_state_MR_26 << "\n";

    List_Ref<double> answers_state_MR_3;
    double eval_state_MR_3;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_3(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_3(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_3, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_3 = pow(2, h(answers_state_MR_3));
    out << "state_MR_3: " << eval_state_MR_3 << "\n";

    List_Ref<double> answers_state_MR_32;
    double eval_state_MR_32;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_32(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_32(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_32, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_32 = pow(2, h(answers_state_MR_32));
    out << "state_MR_32: " << eval_state_MR_32 << "\n";

    List_Ref<double> answers_state_MR_38;
    double eval_state_MR_38;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_38(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_38(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_38, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_38 = pow(2, h(answers_state_MR_38));
    out << "state_MR_38: " << eval_state_MR_38 << "\n";

    List_Ref<double> answers_state_MR_44;
    double eval_state_MR_44;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_44(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_44(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_44, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_44 = pow(2, h(answers_state_MR_44));
    out << "state_MR_44: " << eval_state_MR_44 << "\n";

    List_Ref<double> answers_state_MR_71;
    double eval_state_MR_71;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_71(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_71(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_71, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_71 = pow(2, h(answers_state_MR_71));
    out << "state_MR_71: " << eval_state_MR_71 << "\n";

    List_Ref<double> answers_state_MR_77;
    double eval_state_MR_77;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_77(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_77(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_77, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_77 = pow(2, h(answers_state_MR_77));
    out << "state_MR_77: " << eval_state_MR_77 << "\n";

    List_Ref<double> answers_state_MR_8;
    double eval_state_MR_8;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_8(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_8(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_8, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_8 = pow(2, h(answers_state_MR_8));
    out << "state_MR_8: " << eval_state_MR_8 << "\n";

    List_Ref<double> answers_state_MR_83;
    double eval_state_MR_83;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_83(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_83(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_83, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_83 = pow(2, h(answers_state_MR_83));
    out << "state_MR_83: " << eval_state_MR_83 << "\n";

    List_Ref<double> answers_state_MR_89;
    double eval_state_MR_89;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_89(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_89(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_89, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_89 = pow(2, h(answers_state_MR_89));
    out << "state_MR_89: " << eval_state_MR_89 << "\n";

    List_Ref<double> answers_state_MR_95;
    double eval_state_MR_95;
    for (unsigned int t_0_i = t_0_left_most; t_0_i <= t_0_right_most; ++t_0_i) {
      for (unsigned int t_0_j = t_0_i; t_0_j <= t_0_right_most; ++t_0_j) {
        res_inside = nt_state_MR_95(t_0_i, t_0_j);
        res_outside = nt_outside_state_MR_95(t_0_i, t_0_j);
        if (is_not_empty(res_inside) && is_not_empty(res_outside)) {
          push_back(answers_state_MR_95, (res_inside + res_outside - res_full - res_empty));
        }
      }
    }
    eval_state_MR_95 = pow(2, h(answers_state_MR_95));
    out << "state_MR_95: " << eval_state_MR_95 << "\n";

  }
