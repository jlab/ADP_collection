import pandas as pd
import numpy as np

def minmult(inp:[(int,int)], display_table:bool=False):
    """Computes minimal number of scalar multiplications, necessary to solve
       the given matrix chain multiplication.

    Parameters
    ----------
    inp : [(int,int)]
        List of tuples of matrix dimensions (rows,columns) to multiply
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.

    Returns
    -------
    (int, int, int) where
      first component holds *minimal* number of scalar multiplications used for
      input matrix chain multplication, i.e. optimal order of computation.
      second component is number of rows of the resulting matrix
      third component is number of columns of the resulting matrix

    Notes
    -----
    Example input is [(2,10),(10,50),(50,10),(10,1),(1,20),(20,20)], result
    should be (1460, 2, 20).
    Note that we only obtain the minimal number of multiplications, we do not
    know the order of matrix multiplications that led to this optimal number!
    """
    table = pd.DataFrame(index=range(len(inp)+1), columns=range(len(inp)+1),
                         dtype=object)

    # traverse matrix along its diagonals, start with +1 diagonal (i.e. one off
    # the main diagonal) and continue until upper right corner is reached
    for size in range(1, len(inp)+1):
        for i in range(len(inp)+1-size):
            j = i + size
            #print(i,j)

            if (i+1 == j):
                # if sub-word is only a single matrix:
                table.iloc[i,j] = (0, inp[i][0], inp[i][1])
            else:
                # if there are >1 metrices, define a moving boundary k and
                # combine left and right parts record the best (here minimal
                # regarding first component) candidate seen
                min_candidate = (np.inf, 0, 0)
                for k in range(i+1,j):
                    candidate = (table.iloc[i,k][1] *
                                 table.iloc[i,k][2] *
                                 table.iloc[k,j][2] +
                                 table.iloc[i,k][0] +
                                 table.iloc[k,j][0],
                                 table.iloc[i,k][1], table.iloc[k,j][2])
                    if candidate[0] < min_candidate[0]:
                        min_candidate = candidate
                # write choice into DP matrix
                table.loc[i,j] = min_candidate
    if (display_table):
        display(table)

    return table.iloc[0,len(inp)]
