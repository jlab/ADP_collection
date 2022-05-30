import pandas as pd
import numpy as np

def needlemanwunsch(inpA: str, inpB: str, score_del=-2, score_ins=-2, score_match=+1, score_mismatch=-1, display_table:bool=False, h=np.max):
    """Computes optimal pairwise global alignment score for two input strings.

    Parameters
    ----------
    inpA : str
        First input string to be aligned.
    inpB : str
        Second input string to be aligned.
    score_del : int
        Score of deletion, i.e. use char of inpA, but non of inpB.
    score_int : int
        Score of insertion, i.e. use char of inpB, but non of inpA.
    score_match : int
        Score of identical characters in inpA and inpB.
    score_mismatch : int
        Score of diverging characters in inpA and inpB.
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.
    h : fct
        Objective function.
        E.g. np.max to maximize along all possible alignments: similarity.

    Returns
    -------
    int: the score of the optimal alignment(s).
    """
    table = pd.DataFrame(index=["ε"] + list(inpA), columns=["ε"] + list(inpB), data=0)

    # initialize first column
    for i in range(1, len(inpA)+1):
        table.iloc[i,0] = table.iloc[i-1,0] + score_del
    # initialize first row
    for j in range(1, len(inpB)+1):
        table.iloc[0,j] = table.iloc[0,j-1] + score_ins

    # traverse through rest of table
    for i in range(1, len(inpA)+1):
        for j in range(1, len(inpB)+1):
            table.iloc[i,j] = h([table.iloc[i-1,j-1] + (score_match if inpA[i-1] == inpB[j-1] else score_mismatch),
                                 table.iloc[i,  j-1] + score_ins,
                                 table.iloc[i-1,j  ] + score_del])

    if (display_table):
        display(table)

    return table.iloc[len(inpA), len(inpB)]


def semiglobal(inpA: str, inpB: str, score_del=-2, score_ins=-2, score_match=+1, score_mismatch=-1, display_table:bool=False, h=np.max):
    """Computes optimal pairwise semi-global alignment score for two input strings.
       Note: input is **not** symmetric, i.e. small in large search. inpA is the large one.

    Parameters
    ----------
    inpA : str
        First (longer) input string to be aligned.
    inpB : str
        Second (shorter) input string to be aligned.
    score_del : int
        Score of deletion, i.e. use char of inpA, but non of inpB.
    score_int : int
        Score of insertion, i.e. use char of inpB, but non of inpA.
    score_match : int
        Score of identical characters in inpA and inpB.
    score_mismatch : int
        Score of diverging characters in inpA and inpB.
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.
    h : fct
        Objective function.
        E.g. np.max to maximize along all possible alignments: similarity.

    Returns
    -------
    int: the score of the optimal alignment(s).
    """
    table = pd.DataFrame(index=["ε"] + list(inpA), columns=["ε"] + list(inpB), data=0)

    # initialize first column
    for i in range(1, len(inpA)+1):
        table.iloc[i,0] = 0
    # initialize first row
    for j in range(1, len(inpB)+1):
        table.iloc[0,j] = table.iloc[0,j-1] + score_ins

    # traverse through rest of table
    for i in range(1, len(inpA)+1):
        for j in range(1, len(inpB)+1):
            table.iloc[i,j] = h([table.iloc[i-1,j-1] + (score_match if inpA[i-1] == inpB[j-1] else score_mismatch),
                                 table.iloc[i,  j-1] + score_ins,
                                 table.iloc[i-1,j  ] + score_del])

    if (display_table):
        display(table)

    return h(table.iloc[:, len(inpB)])


def endGapFree(inpA: str, inpB: str, score_del=-2, score_ins=-2, score_match=+1, score_mismatch=-1, display_table:bool=False, h=np.max):
    """Computes optimal pairwise end-gap-free alignment score for two input strings.

    Parameters
    ----------
    inpA : str
        First input string to be aligned.
    inpB : str
        Second input string to be aligned.
    score_del : int
        Score of deletion, i.e. use char of inpA, but non of inpB.
    score_int : int
        Score of insertion, i.e. use char of inpB, but non of inpA.
    score_match : int
        Score of identical characters in inpA and inpB.
    score_mismatch : int
        Score of diverging characters in inpA and inpB.
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.
    h : fct
        Objective function.
        E.g. np.max to maximize along all possible alignments: similarity.

    Returns
    -------
    int: the score of the optimal alignment(s).
    """
    table = pd.DataFrame(index=["ε"] + list(inpA), columns=["ε"] + list(inpB), data=0)

    # initialize first column
    for i in range(1, len(inpA)+1):
        table.iloc[i,0] = 0
    # initialize first row
    for j in range(1, len(inpB)+1):
        table.iloc[0,j] = 0

    # traverse through rest of table
    for i in range(1, len(inpA)+1):
        for j in range(1, len(inpB)+1):
            table.iloc[i,j] = h([table.iloc[i-1,j-1] + (score_match if inpA[i-1] == inpB[j-1] else score_mismatch),
                                 table.iloc[i,  j-1] + score_ins,
                                 table.iloc[i-1,j  ] + score_del])

    if (display_table):
        display(table)

    return h([h(table.iloc[:, len(inpB)]), h(table.iloc[len(inpA), :])])

def smithwaterman(inpA: str, inpB: str, score_del=-2, score_ins=-2, score_match=+1, score_mismatch=-1, display_table:bool=False, h=np.max):
    """Computes optimal pairwise local alignment score for two input strings.

    Parameters
    ----------
    inpA : str
        First input string to be aligned.
    inpB : str
        Second input string to be aligned.
    score_del : int
        Score of deletion, i.e. use char of inpA, but non of inpB.
    score_int : int
        Score of insertion, i.e. use char of inpB, but non of inpA.
    score_match : int
        Score of identical characters in inpA and inpB.
    score_mismatch : int
        Score of diverging characters in inpA and inpB.
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.
    h : fct
        Objective function.
        E.g. np.max to maximize along all possible alignments: similarity.

    Returns
    -------
    int: the score of the optimal alignment(s).
    """
    table = pd.DataFrame(index=["ε"] + list(inpA), columns=["ε"] + list(inpB), data=0)

    # initialize first column
    for i in range(1, len(inpA)+1):
        table.iloc[i,0] = 0
    # initialize first row
    for j in range(1, len(inpB)+1):
        table.iloc[0,j] = 0

    # traverse through rest of table
    for i in range(1, len(inpA)+1):
        for j in range(1, len(inpB)+1):
            table.iloc[i,j] = h([table.iloc[i-1,j-1] + (score_match if inpA[i-1] == inpB[j-1] else score_mismatch),
                                 table.iloc[i,  j-1] + score_ins,
                                 table.iloc[i-1,j  ] + score_del,
                                 0])

    if (display_table):
        display(table)

    return h(h(table))

def gotoh(inpA: str, inpB: str, score_del=-2, score_del_extend=-1, score_ins=-2, score_ins_extend=-1, score_match=+1, score_mismatch=-1, display_table:bool=False, h=np.max):
    """Computes optimal pairwise global alignment score with affine gap costs for two input strings.

    Parameters
    ----------
    inpA : str
        First input string to be aligned.
    inpB : str
        Second input string to be aligned.
    score_del : int
        Score of deletion, i.e. use char of inpA, but non of inpB.
    score_int : int
        Score of insertion, i.e. use char of inpB, but non of inpA.
    score_del_extend : int
        Score of extending an existing deletion. Should be smaller than score_del.
    score_int_extend : int
        Score of extending an existing insertion. Should be smaller than score_ins.
    score_match : int
        Score of identical characters in inpA and inpB.
    score_mismatch : int
        Score of diverging characters in inpA and inpB.
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.
    h : fct
        Objective function.
        E.g. np.max to maximize along all possible alignments: similarity.

    Returns
    -------
    int: the score of the optimal alignment(s).
    """
    forbidden = np.inf
    if h == np.max:
        forbidden = -1 * forbidden

    table_A = pd.DataFrame(index=["ε"] + list(inpA), columns=["ε"] + list(inpB), data=0)
    table_xdel = table_A.copy()
    table_xins = table_A.copy()

    table_xdel.iloc[0,0] = "_"
    table_xins.iloc[0,0] = "_"

    # initialize first columns
    for i in range(1, len(inpA)+1):
        if i > 1:
            table_A.iloc[i,0] = table_A.iloc[i-1,0] + score_del_extend
        else:
            table_A.iloc[i,0] = score_del
        table_xdel.iloc[i,0] = "_"
        table_xins.iloc[i,0] = forbidden

    # initialize first rows
    for j in range(1, len(inpB)+1):
        if j > 1:
            table_A.iloc[0,j] = table_A.iloc[0,j-1] + score_ins_extend
        else:
            table_A.iloc[0,j] = score_ins
        table_xdel.iloc[0,j] = forbidden
        table_xins.iloc[0,j] = "_"

    # traverse through rest of tables
    if True:
        for i in range(1, len(inpA)+1):
            for j in range(1, len(inpB)+1):
                # note: order of table computation is important!
                table_xdel.iloc[i,j] = h([table_A.iloc[i-1,j] + score_del,
                                          table_xdel.iloc[i-1,j] + score_del_extend])

                table_xins.iloc[i,j] = h([table_A.iloc[i,j-1] + score_ins,
                                          table_xins.iloc[i,j-1] + score_ins_extend])

                table_A.iloc[i,j] = h([table_A.iloc[i-1,j-1] + (score_match if inpA[i-1] == inpB[j-1] else score_mismatch),
                                       table_xdel.iloc[i,j],
                                       table_xins.iloc[i,j]])

    if (display_table):
        table_A.columns.name = "A"
        table_xdel.columns.name = "xDel"
        table_xins.columns.name = "xIns"
        display(table_A)
        display(table_xdel)
        display(table_xins)

    return table_A.iloc[len(inpA), len(inpB)]
