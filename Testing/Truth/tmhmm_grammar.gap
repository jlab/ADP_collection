grammar gra_tmhmm uses sig_tmhmm(axiom = state_begin) {
  state_begin = silent_step(transitions_begin) # h;
    transitions_begin =
      trans(CONST_FLOAT(0.549251), state_in10) |
      trans(CONST_FLOAT(0.207469), state_outglob10) |
      trans(CONST_FLOAT(0.24328), state_out10) |
      nil(EMPTY)
      # h;
  state_in10 = step(CONST_CHAR('i'), emissions_in10, transitions_in10) # h;
    emissions_in10 =
      only(CONST_FLOAT(0.0713632), CHAR('A')) |
      only(CONST_FLOAT(0.0188491), CHAR('C')) |
      only(CONST_FLOAT(0.043014), CHAR('D')) |
      only(CONST_FLOAT(0.0471663), CHAR('E')) |
      only(CONST_FLOAT(0.0298789), CHAR('F')) |
      only(CONST_FLOAT(0.0564853), CHAR('G')) |
      only(CONST_FLOAT(0.0233906), CHAR('H')) |
      only(CONST_FLOAT(0.038904), CHAR('I')) |
      only(CONST_FLOAT(0.0894525), CHAR('K')) |
      only(CONST_FLOAT(0.0551519), CHAR('L')) |
      only(CONST_FLOAT(0.0427067), CHAR('M')) |
      only(CONST_FLOAT(0.0544149), CHAR('N')) |
      only(CONST_FLOAT(0.0370019), CHAR('P')) |
      only(CONST_FLOAT(0.0524006), CHAR('Q')) |
      only(CONST_FLOAT(0.114758), CHAR('R')) |
      only(CONST_FLOAT(0.0661936), CHAR('S')) |
      only(CONST_FLOAT(0.0689907), CHAR('T')) |
      only(CONST_FLOAT(0.0416332), CHAR('V')) |
      only(CONST_FLOAT(0.0146085), CHAR('W')) |
      only(CONST_FLOAT(0.0336358), CHAR('Y'))
      # h;
    transitions_in10 =
      trans(CONST_FLOAT(0.995851), state_in11) |
      trans(CONST_FLOAT(0.00111283), state_in29) |
      trans(CONST_FLOAT(0.00303586), state_ohelixi1) |
      nil(EMPTY)
      # h;
  state_in11 = step(CONST_CHAR('i'), emissions_in10, transitions_in11) # h;
    transitions_in11 =
      trans(CONST_FLOAT(0.976066), state_in12) |
      trans(CONST_FLOAT(0.0239339), state_in28) |
      trans(CONST_FLOAT(1.08323e-09), state_in29) |
      nil(EMPTY)
      # h;
  state_in12 = step(CONST_CHAR('i'), emissions_in10, transitions_in12) # h;
    transitions_in12 =
      trans(CONST_FLOAT(0.895077), state_in13) |
      trans(CONST_FLOAT(0.104922), state_in27) |
      trans(CONST_FLOAT(1.76891e-06), state_in28) |
      nil(EMPTY)
      # h;
  state_in13 = step(CONST_CHAR('i'), emissions_in10, transitions_in13) # h;
    transitions_in13 =
      trans(CONST_FLOAT(0.979527), state_in14) |
      trans(CONST_FLOAT(0.0204673), state_in26) |
      trans(CONST_FLOAT(5.81809e-06), state_in27) |
      nil(EMPTY)
      # h;
  state_in14 = step(CONST_CHAR('i'), emissions_in10, transitions_in14) # h;
    transitions_in14 =
      trans(CONST_FLOAT(0.993341), state_in15) |
      trans(CONST_FLOAT(0.00660812), state_in25) |
      trans(CONST_FLOAT(5.08664e-05), state_in26) |
      nil(EMPTY)
      # h;
  state_in15 = step(CONST_CHAR('i'), emissions_in10, transitions_in15) # h;
    transitions_in15 =
      trans(CONST_FLOAT(0.738969), state_in16) |
      trans(CONST_FLOAT(0.159734), state_in24) |
      trans(CONST_FLOAT(0.101297), state_in25) |
      nil(EMPTY)
      # h;
  state_in16 = step(CONST_CHAR('i'), emissions_in10, transitions_in16) # h;
    transitions_in16 =
      trans(CONST_FLOAT(0.999938), state_in17) |
      trans(CONST_FLOAT(1.4427e-06), state_in23) |
      trans(CONST_FLOAT(6.0424e-05), state_in24) |
      nil(EMPTY)
      # h;
  state_in17 = step(CONST_CHAR('i'), emissions_in10, transitions_in17) # h;
    transitions_in17 =
      trans(CONST_FLOAT(0.973203), state_in18) |
      trans(CONST_FLOAT(0.0168132), state_in22) |
      trans(CONST_FLOAT(0.00998417), state_in23) |
      nil(EMPTY)
      # h;
  state_in18 = step(CONST_CHAR('i'), emissions_in10, transitions_in18) # h;
    transitions_in18 =
      trans(CONST_FLOAT(0.977498), state_in19) |
      trans(CONST_FLOAT(0.0217216), state_in21) |
      trans(CONST_FLOAT(0.000780768), state_in22) |
      nil(EMPTY)
      # h;
  state_in19 = step(CONST_CHAR('i'), emissions_in10, transitions_in19) # h;
    transitions_in19 =
      trans(CONST_FLOAT(0.16223), state_in20) |
      trans(CONST_FLOAT(0.10126), state_in21) |
      trans(CONST_FLOAT(0.73651), state_inglob1) |
      nil(EMPTY)
      # h;
  state_in20 = step(CONST_CHAR('i'), emissions_in10, transitions_in20) # h;
    transitions_in20 =
      trans(CONST_FLOAT(1.0), state_in21) |
      nil(EMPTY)
      # h;
  state_in21 = step(CONST_CHAR('i'), emissions_in10, transitions_in21) # h;
    transitions_in21 =
      trans(CONST_FLOAT(1.0), state_in22) |
      nil(EMPTY)
      # h;
  state_in22 = step(CONST_CHAR('i'), emissions_in10, transitions_in22) # h;
    transitions_in22 =
      trans(CONST_FLOAT(1.0), state_in23) |
      nil(EMPTY)
      # h;
  state_in23 = step(CONST_CHAR('i'), emissions_in10, transitions_in23) # h;
    transitions_in23 =
      trans(CONST_FLOAT(1.0), state_in24) |
      nil(EMPTY)
      # h;
  state_in24 = step(CONST_CHAR('i'), emissions_in10, transitions_in24) # h;
    transitions_in24 =
      trans(CONST_FLOAT(1.0), state_in25) |
      nil(EMPTY)
      # h;
  state_in25 = step(CONST_CHAR('i'), emissions_in10, transitions_in25) # h;
    transitions_in25 =
      trans(CONST_FLOAT(1.0), state_in26) |
      nil(EMPTY)
      # h;
  state_in26 = step(CONST_CHAR('i'), emissions_in10, transitions_in26) # h;
    transitions_in26 =
      trans(CONST_FLOAT(1.0), state_in27) |
      nil(EMPTY)
      # h;
  state_in27 = step(CONST_CHAR('i'), emissions_in10, transitions_in27) # h;
    transitions_in27 =
      trans(CONST_FLOAT(1.0), state_in28) |
      nil(EMPTY)
      # h;
  state_in28 = step(CONST_CHAR('i'), emissions_in10, transitions_in28) # h;
    transitions_in28 =
      trans(CONST_FLOAT(1.0), state_in29) |
      nil(EMPTY)
      # h;
  state_in29 = step(CONST_CHAR('i'), emissions_in10, transitions_in29) # h;
    transitions_in29 =
      trans(CONST_FLOAT(1.0), state_ohelixi1) |
      nil(EMPTY)
      # h;
  state_inglob1 = step(CONST_CHAR('i'), emissions_inglob1, transitions_inglob1) # h;
    emissions_inglob1 =
      only(CONST_FLOAT(0.0773341), CHAR('A')) |
      only(CONST_FLOAT(0.0212026), CHAR('C')) |
      only(CONST_FLOAT(0.0556231), CHAR('D')) |
      only(CONST_FLOAT(0.0789783), CHAR('E')) |
      only(CONST_FLOAT(0.0291466), CHAR('F')) |
      only(CONST_FLOAT(0.0821038), CHAR('G')) |
      only(CONST_FLOAT(0.02529), CHAR('H')) |
      only(CONST_FLOAT(0.0392883), CHAR('I')) |
      only(CONST_FLOAT(0.0466567), CHAR('K')) |
      only(CONST_FLOAT(0.0718204), CHAR('L')) |
      only(CONST_FLOAT(0.0191835), CHAR('M')) |
      only(CONST_FLOAT(0.0490524), CHAR('N')) |
      only(CONST_FLOAT(0.0671432), CHAR('P')) |
      only(CONST_FLOAT(0.0472671), CHAR('Q')) |
      only(CONST_FLOAT(0.0492684), CHAR('R')) |
      only(CONST_FLOAT(0.0852997), CHAR('S')) |
      only(CONST_FLOAT(0.0610192), CHAR('T')) |
      only(CONST_FLOAT(0.0528717), CHAR('V')) |
      only(CONST_FLOAT(0.0166592), CHAR('W')) |
      only(CONST_FLOAT(0.0247916), CHAR('Y'))
      # h;
    transitions_inglob1 =
      trans(CONST_FLOAT(0.0132918), state_in20) |
      trans(CONST_FLOAT(0.986708), state_inglob1) |
      nil(EMPTY)
      # h;
  state_outglob10 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob10) # h;
    emissions_outglob10 =
      only(CONST_FLOAT(0.0693743), CHAR('A')) |
      only(CONST_FLOAT(0.0149605), CHAR('C')) |
      only(CONST_FLOAT(0.0406956), CHAR('D')) |
      only(CONST_FLOAT(0.0538397), CHAR('E')) |
      only(CONST_FLOAT(0.0531778), CHAR('F')) |
      only(CONST_FLOAT(0.0792746), CHAR('G')) |
      only(CONST_FLOAT(0.0221055), CHAR('H')) |
      only(CONST_FLOAT(0.0440866), CHAR('I')) |
      only(CONST_FLOAT(0.0565779), CHAR('K')) |
      only(CONST_FLOAT(0.0988165), CHAR('L')) |
      only(CONST_FLOAT(0.0432829), CHAR('M')) |
      only(CONST_FLOAT(0.0414346), CHAR('N')) |
      only(CONST_FLOAT(0.0615562), CHAR('P')) |
      only(CONST_FLOAT(0.0412212), CHAR('Q')) |
      only(CONST_FLOAT(0.0677628), CHAR('R')) |
      only(CONST_FLOAT(0.0732544), CHAR('S')) |
      only(CONST_FLOAT(0.0524824), CHAR('T')) |
      only(CONST_FLOAT(0.0445653), CHAR('V')) |
      only(CONST_FLOAT(0.0140309), CHAR('W')) |
      only(CONST_FLOAT(0.0275), CHAR('Y'))
      # h;
    transitions_outglob10 =
      trans(CONST_FLOAT(1.0), state_outglob11) |
      trans(CONST_FLOAT(0.0), state_outglob29) |
      trans(CONST_FLOAT(0.0), state_ihelixo1) |
      nil(EMPTY)
      # h;
  state_outglob11 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob11) # h;
    transitions_outglob11 =
      trans(CONST_FLOAT(1.0), state_outglob12) |
      trans(CONST_FLOAT(0.0), state_outglob28) |
      trans(CONST_FLOAT(0.0), state_outglob29) |
      nil(EMPTY)
      # h;
  state_outglob12 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob12) # h;
    transitions_outglob12 =
      trans(CONST_FLOAT(1.0), state_outglob13) |
      trans(CONST_FLOAT(0.0), state_outglob27) |
      trans(CONST_FLOAT(0.0), state_outglob28) |
      nil(EMPTY)
      # h;
  state_outglob13 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob13) # h;
    transitions_outglob13 =
      trans(CONST_FLOAT(1.0), state_outglob14) |
      trans(CONST_FLOAT(0.0), state_outglob26) |
      trans(CONST_FLOAT(0.0), state_outglob27) |
      nil(EMPTY)
      # h;
  state_outglob14 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob14) # h;
    transitions_outglob14 =
      trans(CONST_FLOAT(1.0), state_outglob15) |
      trans(CONST_FLOAT(0.0), state_outglob25) |
      trans(CONST_FLOAT(0.0), state_outglob26) |
      nil(EMPTY)
      # h;
  state_outglob15 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob15) # h;
    transitions_outglob15 =
      trans(CONST_FLOAT(1.0), state_outglob16) |
      trans(CONST_FLOAT(0.0), state_outglob24) |
      trans(CONST_FLOAT(0.0), state_outglob25) |
      nil(EMPTY)
      # h;
  state_outglob16 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob16) # h;
    transitions_outglob16 =
      trans(CONST_FLOAT(1.0), state_outglob17) |
      trans(CONST_FLOAT(0.0), state_outglob23) |
      trans(CONST_FLOAT(0.0), state_outglob24) |
      nil(EMPTY)
      # h;
  state_outglob17 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob17) # h;
    transitions_outglob17 =
      trans(CONST_FLOAT(1.0), state_outglob18) |
      trans(CONST_FLOAT(0.0), state_outglob22) |
      trans(CONST_FLOAT(0.0), state_outglob23) |
      nil(EMPTY)
      # h;
  state_outglob18 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob18) # h;
    transitions_outglob18 =
      trans(CONST_FLOAT(1.0), state_outglob19) |
      trans(CONST_FLOAT(0.0), state_outglob21) |
      trans(CONST_FLOAT(0.0), state_outglob22) |
      nil(EMPTY)
      # h;
  state_outglob19 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob19) # h;
    transitions_outglob19 =
      trans(CONST_FLOAT(1.0), state_outglobLong) |
      trans(CONST_FLOAT(0.0), state_outglob20) |
      trans(CONST_FLOAT(0.0), state_outglob21) |
      nil(EMPTY)
      # h;
  state_outglobLong = step(CONST_CHAR('O'), emissions_inglob1, transitions_outglobLong) # h;
    transitions_outglobLong =
      trans(CONST_FLOAT(0.999093), state_outglobLong) |
      trans(CONST_FLOAT(0.000906913), state_outglob20) |
      nil(EMPTY)
      # h;
  state_outglob20 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob20) # h;
    transitions_outglob20 =
      trans(CONST_FLOAT(1.0), state_outglob21) |
      nil(EMPTY)
      # h;
  state_outglob21 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob21) # h;
    transitions_outglob21 =
      trans(CONST_FLOAT(1.0), state_outglob22) |
      nil(EMPTY)
      # h;
  state_outglob22 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob22) # h;
    transitions_outglob22 =
      trans(CONST_FLOAT(1.0), state_outglob23) |
      nil(EMPTY)
      # h;
  state_outglob23 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob23) # h;
    transitions_outglob23 =
      trans(CONST_FLOAT(1.0), state_outglob24) |
      nil(EMPTY)
      # h;
  state_outglob24 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob24) # h;
    transitions_outglob24 =
      trans(CONST_FLOAT(1.0), state_outglob25) |
      nil(EMPTY)
      # h;
  state_outglob25 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob25) # h;
    transitions_outglob25 =
      trans(CONST_FLOAT(1.0), state_outglob26) |
      nil(EMPTY)
      # h;
  state_outglob26 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob26) # h;
    transitions_outglob26 =
      trans(CONST_FLOAT(1.0), state_outglob27) |
      nil(EMPTY)
      # h;
  state_outglob27 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob27) # h;
    transitions_outglob27 =
      trans(CONST_FLOAT(1.0), state_outglob28) |
      nil(EMPTY)
      # h;
  state_outglob28 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob28) # h;
    transitions_outglob28 =
      trans(CONST_FLOAT(1.0), state_outglob29) |
      nil(EMPTY)
      # h;
  state_outglob29 = step(CONST_CHAR('O'), emissions_outglob10, transitions_outglob29) # h;
    transitions_outglob29 =
      trans(CONST_FLOAT(1.0), state_ihelixo1) |
      nil(EMPTY)
      # h;
  state_out10 = step(CONST_CHAR('o'), emissions_out10, transitions_out10) # h;
    emissions_out10 =
      only(CONST_FLOAT(0.0690346), CHAR('A')) |
      only(CONST_FLOAT(0.0129673), CHAR('C')) |
      only(CONST_FLOAT(0.0627756), CHAR('D')) |
      only(CONST_FLOAT(0.0541851), CHAR('E')) |
      only(CONST_FLOAT(0.0425402), CHAR('F')) |
      only(CONST_FLOAT(0.0835626), CHAR('G')) |
      only(CONST_FLOAT(0.0271581), CHAR('H')) |
      only(CONST_FLOAT(0.0292546), CHAR('I')) |
      only(CONST_FLOAT(0.0530401), CHAR('K')) |
      only(CONST_FLOAT(0.0822093), CHAR('L')) |
      only(CONST_FLOAT(0.0334625), CHAR('M')) |
      only(CONST_FLOAT(0.0506017), CHAR('N')) |
      only(CONST_FLOAT(0.0693889), CHAR('P')) |
      only(CONST_FLOAT(0.0389539), CHAR('Q')) |
      only(CONST_FLOAT(0.0432109), CHAR('R')) |
      only(CONST_FLOAT(0.0863749), CHAR('S')) |
      only(CONST_FLOAT(0.0587278), CHAR('T')) |
      only(CONST_FLOAT(0.0480586), CHAR('V')) |
      only(CONST_FLOAT(0.0198473), CHAR('W')) |
      only(CONST_FLOAT(0.0346461), CHAR('Y'))
      # h;
    transitions_out10 =
      trans(CONST_FLOAT(1.0), state_out11) |
      trans(CONST_FLOAT(3.54571e-14), state_out29) |
      trans(CONST_FLOAT(0.0), state_ihelixo1) |
      nil(EMPTY)
      # h;
  state_out11 = step(CONST_CHAR('o'), emissions_out10, transitions_out11) # h;
    transitions_out11 =
      trans(CONST_FLOAT(0.910217), state_out12) |
      trans(CONST_FLOAT(0.0495866), state_out28) |
      trans(CONST_FLOAT(0.0401965), state_out29) |
      nil(EMPTY)
      # h;
  state_out12 = step(CONST_CHAR('o'), emissions_out10, transitions_out12) # h;
    transitions_out12 =
      trans(CONST_FLOAT(0.984498), state_out13) |
      trans(CONST_FLOAT(0.00440955), state_out27) |
      trans(CONST_FLOAT(0.0110921), state_out28) |
      nil(EMPTY)
      # h;
  state_out13 = step(CONST_CHAR('o'), emissions_out10, transitions_out13) # h;
    transitions_out13 =
      trans(CONST_FLOAT(0.997286), state_out14) |
      trans(CONST_FLOAT(0.00258189), state_out26) |
      trans(CONST_FLOAT(0.000132519), state_out27) |
      nil(EMPTY)
      # h;
  state_out14 = step(CONST_CHAR('o'), emissions_out10, transitions_out14) # h;
    transitions_out14 =
      trans(CONST_FLOAT(0.812906), state_out15) |
      trans(CONST_FLOAT(0.0130127), state_out25) |
      trans(CONST_FLOAT(0.174082), state_out26) |
      nil(EMPTY)
      # h;
  state_out15 = step(CONST_CHAR('o'), emissions_out10, transitions_out15) # h;
    transitions_out15 =
      trans(CONST_FLOAT(0.951951), state_out16) |
      trans(CONST_FLOAT(0.0400992), state_out24) |
      trans(CONST_FLOAT(0.00795001), state_out25) |
      nil(EMPTY)
      # h;
  state_out16 = step(CONST_CHAR('o'), emissions_out10, transitions_out16) # h;
    transitions_out16 =
      trans(CONST_FLOAT(0.660205), state_out17) |
      trans(CONST_FLOAT(0.33979), state_out23) |
      trans(CONST_FLOAT(4.76867e-06), state_out24) |
      nil(EMPTY)
      # h;
  state_out17 = step(CONST_CHAR('o'), emissions_out10, transitions_out17) # h;
    transitions_out17 =
      trans(CONST_FLOAT(0.992733), state_out18) |
      trans(CONST_FLOAT(0.0072618), state_out22) |
      trans(CONST_FLOAT(5.34599e-06), state_out23) |
      nil(EMPTY)
      # h;
  state_out18 = step(CONST_CHAR('o'), emissions_out10, transitions_out18) # h;
    transitions_out18 =
      trans(CONST_FLOAT(0.971165), state_out19) |
      trans(CONST_FLOAT(0.0119931), state_out21) |
      trans(CONST_FLOAT(0.0168416), state_out22) |
      nil(EMPTY)
      # h;
  state_out19 = step(CONST_CHAR('o'), emissions_out10, transitions_out19) # h;
    transitions_out19 =
      trans(CONST_FLOAT(0.770716), state_outglobShort) |
      trans(CONST_FLOAT(0.00133523), state_out20) |
      trans(CONST_FLOAT(0.227948), state_out21) |
      nil(EMPTY)
      # h;
  state_outglobShort = step(CONST_CHAR('o'), emissions_inglob1, transitions_outglobShort) # h;
    transitions_outglobShort =
      trans(CONST_FLOAT(0.960334), state_outglobShort) |
      trans(CONST_FLOAT(0.0396664), state_out20) |
      nil(EMPTY)
      # h;
  state_out20 = step(CONST_CHAR('o'), emissions_out10, transitions_out20) # h;
    transitions_out20 =
      trans(CONST_FLOAT(1.0), state_out21) |
      nil(EMPTY)
      # h;
  state_out21 = step(CONST_CHAR('o'), emissions_out10, transitions_out21) # h;
    transitions_out21 =
      trans(CONST_FLOAT(1.0), state_out22) |
      nil(EMPTY)
      # h;
  state_out22 = step(CONST_CHAR('o'), emissions_out10, transitions_out22) # h;
    transitions_out22 =
      trans(CONST_FLOAT(1.0), state_out23) |
      nil(EMPTY)
      # h;
  state_out23 = step(CONST_CHAR('o'), emissions_out10, transitions_out23) # h;
    transitions_out23 =
      trans(CONST_FLOAT(1.0), state_out24) |
      nil(EMPTY)
      # h;
  state_out24 = step(CONST_CHAR('o'), emissions_out10, transitions_out24) # h;
    transitions_out24 =
      trans(CONST_FLOAT(1.0), state_out25) |
      nil(EMPTY)
      # h;
  state_out25 = step(CONST_CHAR('o'), emissions_out10, transitions_out25) # h;
    transitions_out25 =
      trans(CONST_FLOAT(1.0), state_out26) |
      nil(EMPTY)
      # h;
  state_out26 = step(CONST_CHAR('o'), emissions_out10, transitions_out26) # h;
    transitions_out26 =
      trans(CONST_FLOAT(1.0), state_out27) |
      nil(EMPTY)
      # h;
  state_out27 = step(CONST_CHAR('o'), emissions_out10, transitions_out27) # h;
    transitions_out27 =
      trans(CONST_FLOAT(1.0), state_out28) |
      nil(EMPTY)
      # h;
  state_out28 = step(CONST_CHAR('o'), emissions_out10, transitions_out28) # h;
    transitions_out28 =
      trans(CONST_FLOAT(1.0), state_out29) |
      nil(EMPTY)
      # h;
  state_out29 = step(CONST_CHAR('o'), emissions_out10, transitions_out29) # h;
    transitions_out29 =
      trans(CONST_FLOAT(1.0), state_ihelixo1) |
      nil(EMPTY)
      # h;
  state_ohelixi1 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ohelixi1) # h;
    emissions_ohelixi1 =
      only(CONST_FLOAT(0.0890049), CHAR('A')) |
      only(CONST_FLOAT(0.0170933), CHAR('C')) |
      only(CONST_FLOAT(0.00159548), CHAR('D')) |
      only(CONST_FLOAT(0.00489647), CHAR('E')) |
      only(CONST_FLOAT(0.108081), CHAR('F')) |
      only(CONST_FLOAT(0.0692068), CHAR('G')) |
      only(CONST_FLOAT(0.00923517), CHAR('H')) |
      only(CONST_FLOAT(0.113471), CHAR('I')) |
      only(CONST_FLOAT(0.00466208), CHAR('K')) |
      only(CONST_FLOAT(0.19417), CHAR('L')) |
      only(CONST_FLOAT(0.0239901), CHAR('M')) |
      only(CONST_FLOAT(0.0233656), CHAR('N')) |
      only(CONST_FLOAT(0.0145168), CHAR('P')) |
      only(CONST_FLOAT(0.00487025), CHAR('Q')) |
      only(CONST_FLOAT(0.0127643), CHAR('R')) |
      only(CONST_FLOAT(0.0455139), CHAR('S')) |
      only(CONST_FLOAT(0.0292949), CHAR('T')) |
      only(CONST_FLOAT(0.128208), CHAR('V')) |
      only(CONST_FLOAT(0.0399529), CHAR('W')) |
      only(CONST_FLOAT(0.0661077), CHAR('Y'))
      # h;
    transitions_ohelixi1 =
      trans(CONST_FLOAT(1.0), state_ohelixi2)
      # h;
  state_ohelixi2 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ohelixi2) # h;
    transitions_ohelixi2 =
      trans(CONST_FLOAT(1.0), state_ohelixi3)
      # h;
  state_ohelixi3 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ohelixi3) # h;
    transitions_ohelixi3 =
      trans(CONST_FLOAT(1.0), state_ohelixi4)
      # h;
  state_ohelixi4 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ohelixi4) # h;
    transitions_ohelixi4 =
      trans(CONST_FLOAT(1.0), state_ohelixi5)
      # h;
  state_ohelixi5 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ohelixi5) # h;
    transitions_ohelixi5 =
      trans(CONST_FLOAT(1.0), state_ohelixi6)
      # h;
  state_ohelixi6 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelixi6) # h;
    transitions_ohelixi6 =
      trans(CONST_FLOAT(1.0), state_ohelixi7)
      # h;
  state_ohelixi7 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelixi7) # h;
    transitions_ohelixi7 =
      trans(CONST_FLOAT(1.0), state_ohelixm)
      # h;
  state_ohelixm = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelixm) # h;
    emissions_ohelixm =
      only(CONST_FLOAT(0.110896), CHAR('A')) |
      only(CONST_FLOAT(0.0254931), CHAR('C')) |
      only(CONST_FLOAT(0.00235724), CHAR('D')) |
      only(CONST_FLOAT(0.00383965), CHAR('E')) |
      only(CONST_FLOAT(0.0942003), CHAR('F')) |
      only(CONST_FLOAT(0.0818095), CHAR('G')) |
      only(CONST_FLOAT(0.00408389), CHAR('H')) |
      only(CONST_FLOAT(0.144377), CHAR('I')) |
      only(CONST_FLOAT(0.00236432), CHAR('K')) |
      only(CONST_FLOAT(0.182902), CHAR('L')) |
      only(CONST_FLOAT(0.0385107), CHAR('M')) |
      only(CONST_FLOAT(0.00978815), CHAR('N')) |
      only(CONST_FLOAT(0.0201094), CHAR('P')) |
      only(CONST_FLOAT(0.00437833), CHAR('Q')) |
      only(CONST_FLOAT(0.00115335), CHAR('R')) |
      only(CONST_FLOAT(0.0421756), CHAR('S')) |
      only(CONST_FLOAT(0.0514071), CHAR('T')) |
      only(CONST_FLOAT(0.132167), CHAR('V')) |
      only(CONST_FLOAT(0.0158643), CHAR('W')) |
      only(CONST_FLOAT(0.0321232), CHAR('Y'))
      # h;
    transitions_ohelixm =
      trans(CONST_FLOAT(0.000534023), state_ohelix2) |
      trans(CONST_FLOAT(0.000567583), state_ohelix3) |
      trans(CONST_FLOAT(0.00064457), state_ohelix4) |
      trans(CONST_FLOAT(0.00159544), state_ohelix5) |
      trans(CONST_FLOAT(0.000669433), state_ohelix6) |
      trans(CONST_FLOAT(0.00161008), state_ohelix7) |
      trans(CONST_FLOAT(0.000762887), state_ohelix8) |
      trans(CONST_FLOAT(0.000789084), state_ohelix9) |
      trans(CONST_FLOAT(0.000868204), state_ohelix10) |
      trans(CONST_FLOAT(0.00519996), state_ohelix11) |
      trans(CONST_FLOAT(0.00774891), state_ohelix12) |
      trans(CONST_FLOAT(0.0108947), state_ohelix13) |
      trans(CONST_FLOAT(0.697722), state_ohelix14) |
      trans(CONST_FLOAT(0.0444777), state_ohelix15) |
      trans(CONST_FLOAT(0.0328707), state_ohelix16) |
      trans(CONST_FLOAT(0.111827), state_ohelix17) |
      trans(CONST_FLOAT(0.0324248), state_ohelix18) |
      trans(CONST_FLOAT(0.0448694), state_ohelix19) |
      trans(CONST_FLOAT(0.00212234), state_ohelix20) |
      trans(CONST_FLOAT(0.00107586), state_ohelix21) |
      trans(CONST_FLOAT(0.00072618), state_ohelixo1)
      # h;
  state_ohelix2 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix2) # h;
    transitions_ohelix2 =
      trans(CONST_FLOAT(1.0), state_ohelix3)
      # h;
  state_ohelix3 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix3) # h;
    transitions_ohelix3 =
      trans(CONST_FLOAT(1.0), state_ohelix4)
      # h;
  state_ohelix4 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix4) # h;
    transitions_ohelix4 =
      trans(CONST_FLOAT(1.0), state_ohelix5)
      # h;
  state_ohelix5 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix5) # h;
    transitions_ohelix5 =
      trans(CONST_FLOAT(1.0), state_ohelix6)
      # h;
  state_ohelix6 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix6) # h;
    transitions_ohelix6 =
      trans(CONST_FLOAT(1.0), state_ohelix7)
      # h;
  state_ohelix7 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix7) # h;
    transitions_ohelix7 =
      trans(CONST_FLOAT(1.0), state_ohelix8)
      # h;
  state_ohelix8 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix8) # h;
    transitions_ohelix8 =
      trans(CONST_FLOAT(1.0), state_ohelix9)
      # h;
  state_ohelix9 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix9) # h;
    transitions_ohelix9 =
      trans(CONST_FLOAT(1.0), state_ohelix10)
      # h;
  state_ohelix10 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix10) # h;
    transitions_ohelix10 =
      trans(CONST_FLOAT(1.0), state_ohelix11)
      # h;
  state_ohelix11 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix11) # h;
    transitions_ohelix11 =
      trans(CONST_FLOAT(1.0), state_ohelix12)
      # h;
  state_ohelix12 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix12) # h;
    transitions_ohelix12 =
      trans(CONST_FLOAT(1.0), state_ohelix13)
      # h;
  state_ohelix13 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix13) # h;
    transitions_ohelix13 =
      trans(CONST_FLOAT(1.0), state_ohelix14)
      # h;
  state_ohelix14 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix14) # h;
    transitions_ohelix14 =
      trans(CONST_FLOAT(1.0), state_ohelix15)
      # h;
  state_ohelix15 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix15) # h;
    transitions_ohelix15 =
      trans(CONST_FLOAT(1.0), state_ohelix16)
      # h;
  state_ohelix16 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix16) # h;
    transitions_ohelix16 =
      trans(CONST_FLOAT(1.0), state_ohelix17)
      # h;
  state_ohelix17 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix17) # h;
    transitions_ohelix17 =
      trans(CONST_FLOAT(1.0), state_ohelix18)
      # h;
  state_ohelix18 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix18) # h;
    transitions_ohelix18 =
      trans(CONST_FLOAT(1.0), state_ohelix19)
      # h;
  state_ohelix19 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix19) # h;
    transitions_ohelix19 =
      trans(CONST_FLOAT(1.0), state_ohelix20)
      # h;
  state_ohelix20 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix20) # h;
    transitions_ohelix20 =
      trans(CONST_FLOAT(1.0), state_ohelix21)
      # h;
  state_ohelix21 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelix21) # h;
    transitions_ohelix21 =
      trans(CONST_FLOAT(1.0), state_ohelixo1)
      # h;
  state_ohelixo1 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelixo1) # h;
    transitions_ohelixo1 =
      trans(CONST_FLOAT(1.0), state_ohelixo2)
      # h;
  state_ohelixo2 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ohelixo2) # h;
    transitions_ohelixo2 =
      trans(CONST_FLOAT(1.0), state_ohelixo3)
      # h;
  state_ohelixo3 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ohelixo3) # h;
    transitions_ohelixo3 =
      trans(CONST_FLOAT(1.0), state_ohelixo4)
      # h;
  state_ohelixo4 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ohelixo4) # h;
    transitions_ohelixo4 =
      trans(CONST_FLOAT(1.0), state_ohelixo5)
      # h;
  state_ohelixo5 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ohelixo5) # h;
    transitions_ohelixo5 =
      trans(CONST_FLOAT(1.0), state_ohelixo6)
      # h;
  state_ohelixo6 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ohelixo6) # h;
    transitions_ohelixo6 =
      trans(CONST_FLOAT(1.0), state_ohelixo7)
      # h;
  state_ohelixo7 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ohelixo7) # h;
    emissions_ohelixo7 =
      only(CONST_FLOAT(0.110353), CHAR('A')) |
      only(CONST_FLOAT(0.00498206), CHAR('C')) |
      only(CONST_FLOAT(0.00469973), CHAR('D')) |
      only(CONST_FLOAT(0.00649427), CHAR('E')) |
      only(CONST_FLOAT(0.0973043), CHAR('F')) |
      only(CONST_FLOAT(0.0737631), CHAR('G')) |
      only(CONST_FLOAT(0.0119931), CHAR('H')) |
      only(CONST_FLOAT(0.12167), CHAR('I')) |
      only(CONST_FLOAT(0.00180854), CHAR('K')) |
      only(CONST_FLOAT(0.157124), CHAR('L')) |
      only(CONST_FLOAT(0.044721), CHAR('M')) |
      only(CONST_FLOAT(0.0107496), CHAR('N')) |
      only(CONST_FLOAT(0.0283821), CHAR('P')) |
      only(CONST_FLOAT(0.0143416), CHAR('Q')) |
      only(CONST_FLOAT(0.00857182), CHAR('R')) |
      only(CONST_FLOAT(0.0402204), CHAR('S')) |
      only(CONST_FLOAT(0.0501039), CHAR('T')) |
      only(CONST_FLOAT(0.107462), CHAR('V')) |
      only(CONST_FLOAT(0.0501891), CHAR('W')) |
      only(CONST_FLOAT(0.0550665), CHAR('Y'))
      # h;
    transitions_ohelixo7 =
      trans(CONST_FLOAT(0.0757404), state_outglob10) |
      trans(CONST_FLOAT(0.92426), state_out10)
      # h;
  state_ihelixo1 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ihelixo1) # h;
    transitions_ihelixo1 =
      trans(CONST_FLOAT(1.0), state_ihelixo2)
      # h;
  state_ihelixo2 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ihelixo2) # h;
    transitions_ihelixo2 =
      trans(CONST_FLOAT(1.0), state_ihelixo3)
      # h;
  state_ihelixo3 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ihelixo3) # h;
    transitions_ihelixo3 =
      trans(CONST_FLOAT(1.0), state_ihelixo4)
      # h;
  state_ihelixo4 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ihelixo4) # h;
    transitions_ihelixo4 =
      trans(CONST_FLOAT(1.0), state_ihelixo5)
      # h;
  state_ihelixo5 = step(CONST_CHAR('M'), emissions_ohelixo7, transitions_ihelixo5) # h;
    transitions_ihelixo5 =
      trans(CONST_FLOAT(1.0), state_ihelixo6)
      # h;
  state_ihelixo6 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelixo6) # h;
    transitions_ihelixo6 =
      trans(CONST_FLOAT(1.0), state_ihelixo7)
      # h;
  state_ihelixo7 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelixo7) # h;
    transitions_ihelixo7 =
      trans(CONST_FLOAT(1.0), state_ihelixm)
      # h;
  state_ihelixm = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelixm) # h;
    transitions_ihelixm =
      trans(CONST_FLOAT(0.000534023), state_ihelix2) |
      trans(CONST_FLOAT(0.000567583), state_ihelix3) |
      trans(CONST_FLOAT(0.00064457), state_ihelix4) |
      trans(CONST_FLOAT(0.00159544), state_ihelix5) |
      trans(CONST_FLOAT(0.000669433), state_ihelix6) |
      trans(CONST_FLOAT(0.00161008), state_ihelix7) |
      trans(CONST_FLOAT(0.000762887), state_ihelix8) |
      trans(CONST_FLOAT(0.000789084), state_ihelix9) |
      trans(CONST_FLOAT(0.000868204), state_ihelix10) |
      trans(CONST_FLOAT(0.00519996), state_ihelix11) |
      trans(CONST_FLOAT(0.00774891), state_ihelix12) |
      trans(CONST_FLOAT(0.0108947), state_ihelix13) |
      trans(CONST_FLOAT(0.697722), state_ihelix14) |
      trans(CONST_FLOAT(0.0444777), state_ihelix15) |
      trans(CONST_FLOAT(0.0328707), state_ihelix16) |
      trans(CONST_FLOAT(0.111827), state_ihelix17) |
      trans(CONST_FLOAT(0.0324248), state_ihelix18) |
      trans(CONST_FLOAT(0.0448694), state_ihelix19) |
      trans(CONST_FLOAT(0.00212234), state_ihelix20) |
      trans(CONST_FLOAT(0.00107586), state_ihelix21) |
      trans(CONST_FLOAT(0.00072618), state_ihelixi1)
      # h;
  state_ihelix2 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix2) # h;
    transitions_ihelix2 =
      trans(CONST_FLOAT(1.0), state_ihelix3)
      # h;
  state_ihelix3 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix3) # h;
    transitions_ihelix3 =
      trans(CONST_FLOAT(1.0), state_ihelix4)
      # h;
  state_ihelix4 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix4) # h;
    transitions_ihelix4 =
      trans(CONST_FLOAT(1.0), state_ihelix5)
      # h;
  state_ihelix5 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix5) # h;
    transitions_ihelix5 =
      trans(CONST_FLOAT(1.0), state_ihelix6)
      # h;
  state_ihelix6 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix6) # h;
    transitions_ihelix6 =
      trans(CONST_FLOAT(1.0), state_ihelix7)
      # h;
  state_ihelix7 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix7) # h;
    transitions_ihelix7 =
      trans(CONST_FLOAT(1.0), state_ihelix8)
      # h;
  state_ihelix8 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix8) # h;
    transitions_ihelix8 =
      trans(CONST_FLOAT(1.0), state_ihelix9)
      # h;
  state_ihelix9 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix9) # h;
    transitions_ihelix9 =
      trans(CONST_FLOAT(1.0), state_ihelix10)
      # h;
  state_ihelix10 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix10) # h;
    transitions_ihelix10 =
      trans(CONST_FLOAT(1.0), state_ihelix11)
      # h;
  state_ihelix11 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix11) # h;
    transitions_ihelix11 =
      trans(CONST_FLOAT(1.0), state_ihelix12)
      # h;
  state_ihelix12 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix12) # h;
    transitions_ihelix12 =
      trans(CONST_FLOAT(1.0), state_ihelix13)
      # h;
  state_ihelix13 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix13) # h;
    transitions_ihelix13 =
      trans(CONST_FLOAT(1.0), state_ihelix14)
      # h;
  state_ihelix14 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix14) # h;
    transitions_ihelix14 =
      trans(CONST_FLOAT(1.0), state_ihelix15)
      # h;
  state_ihelix15 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix15) # h;
    transitions_ihelix15 =
      trans(CONST_FLOAT(1.0), state_ihelix16)
      # h;
  state_ihelix16 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix16) # h;
    transitions_ihelix16 =
      trans(CONST_FLOAT(1.0), state_ihelix17)
      # h;
  state_ihelix17 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix17) # h;
    transitions_ihelix17 =
      trans(CONST_FLOAT(1.0), state_ihelix18)
      # h;
  state_ihelix18 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix18) # h;
    transitions_ihelix18 =
      trans(CONST_FLOAT(1.0), state_ihelix19)
      # h;
  state_ihelix19 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix19) # h;
    transitions_ihelix19 =
      trans(CONST_FLOAT(1.0), state_ihelix20)
      # h;
  state_ihelix20 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix20) # h;
    transitions_ihelix20 =
      trans(CONST_FLOAT(1.0), state_ihelix21)
      # h;
  state_ihelix21 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelix21) # h;
    transitions_ihelix21 =
      trans(CONST_FLOAT(1.0), state_ihelixi1)
      # h;
  state_ihelixi1 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelixi1) # h;
    transitions_ihelixi1 =
      trans(CONST_FLOAT(1.0), state_ihelixi2)
      # h;
  state_ihelixi2 = step(CONST_CHAR('M'), emissions_ohelixm, transitions_ihelixi2) # h;
    transitions_ihelixi2 =
      trans(CONST_FLOAT(1.0), state_ihelixi3)
      # h;
  state_ihelixi3 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ihelixi3) # h;
    transitions_ihelixi3 =
      trans(CONST_FLOAT(1.0), state_ihelixi4)
      # h;
  state_ihelixi4 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ihelixi4) # h;
    transitions_ihelixi4 =
      trans(CONST_FLOAT(1.0), state_ihelixi5)
      # h;
  state_ihelixi5 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ihelixi5) # h;
    transitions_ihelixi5 =
      trans(CONST_FLOAT(1.0), state_ihelixi6)
      # h;
  state_ihelixi6 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ihelixi6) # h;
    transitions_ihelixi6 =
      trans(CONST_FLOAT(1.0), state_ihelixi7)
      # h;
  state_ihelixi7 = step(CONST_CHAR('M'), emissions_ohelixi1, transitions_ihelixi7) # h;
    transitions_ihelixi7 =
      trans(CONST_FLOAT(1.0), state_in10)
      # h;
}
