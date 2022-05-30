import pandas as pd
import numpy as np

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
                table.iloc[i,j] = inp[i]
            else:
                opt_candidate = None
                # instead of manually checking if we are at a legal sub-word
                # we can also make use of the fact that numbers and operators
                # alternate and we thus increase the loop variable k by 2
                for k in range(i+1,j, 2):
                    candidate = None
                    if inp[k] == '+':
                        candidate = table.iloc[i,k] + table.iloc[k+1,j]
                    elif inp[k] == '*':
                        candidate = table.iloc[i,k] * table.iloc[k+1,j]
                    # operator - violates Bellman's Principle in general!
                    elif inp[k] == '-':
                        candidate = table.iloc[i,k] - table.iloc[k+1,j]

                    if (opt_candidate is None):
                        opt_candidate = candidate
                    else:
                        opt_candidate = h([candidate, opt_candidate])
                table.iloc[i,j] = opt_candidate

    if (display_table):
        display(table)

    return table.iloc[0,len(inp)]
