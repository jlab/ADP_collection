import pandas as pd
import numpy as np

def addTrace(df : pd.DataFrame, idx_me, idx_subword, val):
    key = (idx_me, idx_subword)
    if key not in df:
        df[key] = []
    df[key].append(val)

def elmamun(inp:[], h=np.min, display_table:bool=False):
    """Solves el Mamun's problem of placing parenthesis such that the value
       of a formula is either minimized (if he is the buyer) or maximized
       (if he is the seller).

    Parameters
    ----------
    inp : []
        Math formula (without parenthesis) as list, i.e. every number and
        every operator are list elements, e.g. [1,'+',2,'*',3,'*',4,'+',5]
    h : function
        The objective function. Either np.min or np.max
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.

    Returns
    -------
    int, the result placing parenthesis in the provided math formula.

    Notes
    -----
    Example input is [1,'+',2,'*',3,'*',4,'+',5], result should be 30.
    If h=np.max (you are the seller), result is 81.
    Note that we only obtain the minimal or maximal "costs", we do not
    know the actual placements of the parenthesis! This would require proper
    backtracing (not implemented).
    """

    table = pd.DataFrame(index=range(len(inp)+1), columns=range(len(inp)+1),
                         dtype=object)
    q = dict()
    q2 = dict()

    # traverse matrix along its diagonals, start with +1 diagonal (i.e. one off
    # the main diagonal) and continue until upper right corner is reached
    for size in range(1, len(inp)+1):
        for i in range(len(inp)+1-size):
            j = i + size

            # only consider sub-words that form a valid math expression
            # e.g. allow [1, '+', 2], but not [1, '+']
            if ((type(inp[i]) != int) or (type(inp[j-1]) != int)):
                continue

            if (i+1 == j):
                if (i,j) not in q:
                    q[i,j] = []
                q[i,j].append(1)
                table.iloc[i,j] = 1 #inp[i]
                q[i,j] /= np.sum(q[i,j])
                addTrace(q2, ('nt',i,j), None, 0)
                #q2[i,j] = 1
                print(i,j)
            else:
                opt_candidate = None
                # instead of manually checking if we are at a legal sub-word
                # we can also make use of the fact that numbers and operators
                # alternate and we thus increase the loop variable k by 2
                qsum = 0
                for k in range(i+1,j, 2):
                    print(i,j,k)
                    candidate = None
                    if inp[k] == '+':
                        addTrace(q2, ('nt',i,j), ('nt',i,k), 1)
                        addTrace(q2, ('nt',i,j), ('nt',k+1,j), 1)
                        candidate = table.iloc[i,k] * table.iloc[k+1,j]
                    elif inp[k] == '*':
                        addTrace(q2, ('nt',i,j), ('nt',i,k), 2)
                        addTrace(q2, ('nt',i,j), ('nt',k+1,j), 2)
                        candidate = table.iloc[i,k] * table.iloc[k+1,j]
                    # operator - violates Bellman's Principle in general!
                    elif inp[k] == '-':
                        addTrace(q2, ('nt',i,j), ('nt',i,k), 3)
                        addTrace(q2, ('nt',i,j), ('nt',k+1,j), 3)
                        candidate = table.iloc[i,k] * table.iloc[k+1,j]

                    if (i,j) not in q:
                        q[i,j] = []
                    q[i,j].append(candidate)
                    #q2[i,j,k] = candidate
                    qsum += candidate
                    if (opt_candidate is None):
                        opt_candidate = candidate
                    else:
                        opt_candidate = h([candidate, opt_candidate])
                table.iloc[i,j] = opt_candidate
                q[i,j] /= np.sum(q[i,j])
                #for k in range(i+1,j, 2):
                #    if inp[k] in ['+','*','-']:
                #        q2[i,j,k] /= qsum
    if (display_table):
        display(table.fillna('   .   '))

    return table.iloc[0,len(inp)], q, q2

def elmamun_rev(inp:[], q, h=np.min, display_table:bool=False, basis=1):
    table = pd.DataFrame(index=range(len(inp)+1), columns=range(len(inp)+1),
                         dtype=object)

    # traverse matrix along its diagonals, start with +1 diagonal (i.e. one off
    # the main diagonal) and continue until upper right corner is reached
    for size in reversed(range(1, len(inp)+1)):
        for i in reversed(range(len(inp)+1-size)):
            j = i + size

            # only consider sub-words that form a valid math expression
            # e.g. allow [1, '+', 2], but not [1, '+']
            if ((type(inp[i]) != int) or (type(inp[j-1]) != int)):
                continue

            if (i == 0) and (j == len(inp)):
                table.iloc[i,j] = basis
            else:
                opt_candidate = None
                # instead of manually checking if we are at a legal sub-word
                # we can also make use of the fact that numbers and operators
                # alternate and we thus increase the loop variable k by 2
                for k in range(0,i,2):
                    print('left', i,j,k)
                for k in range(j+2,len(inp)+1,2):
                    print('right', i,j,k)
                for k in reversed(range(i+1,j, 2)):
                    #print(i,j,k)
                    candidate = None
                    if inp[k] in ['+','*','-']:
                        #print(i,j,k,table.iloc[i,k],table.iloc[k+1,j])
                        candidate = table.iloc[i,k] * q[i,j,k] * table.iloc[k+1,j] * q[i,j,k]

                    if (opt_candidate is None):
                        opt_candidate = candidate
                    else:
                        #print(i,j,k, candidate)
                        opt_candidate = h([candidate, opt_candidate])
                    #print(i,j,k, candidate)
                #print(i,j, opt_candidate)
                table.iloc[i,j] = opt_candidate

    if (display_table):
        display(table)
