from typing import List, Set, Dict, Tuple, Optional

# define Branch, Nil and Leaf as datatypes to later recurse along structure
class Branch:
    def __init__(self, left, key, right):
        self.left = left
        self.key = key
        self.right = right

class Nil:
    def __init__(self):
        self.key = None

class Leaf:
    def __init__(self, key):
        self.key = key

def determine_depth(tree, depth=1):
    """Top down traversal to annotate each node with its depth.

    Parameters
    ----------
    tree : Tree
        The tree object.
    depth : int
        Depth at the root of the tree, should be 1.
    Returns
    -------
    nothing, but input tree is updated.
    """
    if type(tree) == Nil:
        tree.depth = depth + 0
    elif type(tree) == Leaf:
        tree.depth = depth + 0
    elif type(tree) == Branch:
        tree.depth = depth + 0
        determine_depth(tree.left, depth+1)
        determine_depth(tree.right, depth+1)

def mean_access_time(tree, probabilities):
    """Top down traversal to multiply key access probability with node depth.

    Parameters
    ----------
    tree : Tree
        The tree object.
    probabilities : dict(int: float)
        A dictionary holding key access probabilities for all keys in tree.

    Returns
    -------
    The mean access time of this tree.

    Notes
    -----
    Ensure that tree has annotated depth information!
    Also ensure that all keys come with probabilities.
    """
    if type(tree) == Nil:
        return 0
    elif type(tree) == Leaf:
        return tree.depth * probabilities[tree.key]
    elif type(tree) == Branch:
        return tree.depth * probabilities[tree.key] \
             + mean_access_time(tree.left, probabilities) \
             + mean_access_time(tree.right, probabilities)

def mean_access_time_bottomup(tree, probabilities):
    """Same as mean_access_time, but NOT using node depth."""
    assert (not hasattr(tree, "depth")), "Using depth is cheating!!"

    if type(tree) == Nil:
        return {'mean': 0,
                'yield': 0}
    elif type(tree) == Leaf:
        return {'mean': probabilities[tree.key],
                'yield': probabilities[tree.key]}
    elif type(tree) == Branch:
        left = mean_access_time_bottomup(tree.left, probabilities)
        right = mean_access_time_bottomup(tree.right, probabilities)
        return {'mean':  left['yield'] + right['yield'] + probabilities[tree.key] + left['mean'] + right['mean'],
                'yield': left['yield'] + right['yield'] + probabilities[tree.key]}


def min_mean_access_time(inp:[int], probabilities:Dict[int, float], display_table:bool=False):
    """Algorithm to find minimal mean access time.

    Parameters
    ----------
    inp : [int]
        List of "keys" of type int.
    probabilities : dict(int: float)
        A dictionary holding key access probabilities for all keys in tree.
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.
    Returns
    -------
    """
    table = pd.DataFrame(index=range(len(inp)+1), columns=range(len(inp)+1), dtype=object)

    # traverse matrix along its diagonals, start with +1 diagonal (i.e. one off the main diagonal)
    # and continue until upper right corner is reached
    for size in range(0, len(inp)+1):
        for i in range(len(inp)+1-size):
            j = i + size

            if (i == j):
                # empty sub-word is Nil
                table.iloc[i,j] = (0, 0)
            elif (i+1 == j):
                # if sub-word is only a single key, i.e. a Leaf
                table.iloc[i,j] = (probabilities[inp[i]], probabilities[inp[i]])
            else:
                # sub-word can form a Branch
                opt_candidate = (np.inf, 0)
                for k in range(i,j):
                    left = table.iloc[i,k]
                    right = table.iloc[k+1,j]
                    mean = left[1] + right[1] + probabilities[inp[k]] + left[0] + right[0]
                    _yield = left[1] + right[1] + probabilities[inp[k]]

                    candidate = (mean, _yield)
                    if candidate[0] < opt_candidate[0]:
                        opt_candidate = candidate
                # write choice into DP matrix
                table.loc[i,j] = opt_candidate

    if (display_table):
        display(table)

    return table.iloc[0,len(inp)]
