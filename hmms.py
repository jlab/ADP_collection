import pandas as pd
import numpy as np

def viterbi(inp, startstate, transitions, emissions, display_table:bool=False, h=np.max):
    """Compute most probable hidden state path for observed emission sequence.

    Parameters
    ----------
    inp : [str]
        List of observed emission characters.
    startstate : str
        Designated state from which all paths originate.
    transitions : dict[(str, str): float]
        Dictionary holding transition probabilities from start (first element) to
        target (second element) state. Value is transition probability.
    emissions : dict[(str, str): float]
        Dictionary holding emission probabilities. First key element is state,
        second key element is observation. Value is emission probability.
    display_table : bool
        If true, pandas dataframe holding dynamic programming matrix will be
        displayed.

    Returns
    -------
    Probability of the most likely (hidden) state path.

    Raises
    ------
    If some basic assertions fail, like startstate not in set of states or
    states between emissions and transitions do not match. One could implement
    more tests, like checking of outgoing transitions sum to 1.0, ...
    """
    states = sorted(list(set(map(lambda x: x[0], transitions.keys()))))

    # sanity checks
    assert startstate in states, "start-state not in list of states!"
    assert set(states) == set(map(lambda x: x[0], emissions.keys())), "emission and transition states do not match!"

    table = pd.DataFrame(index=states, columns=["ε"] + inp, data=0.0)

    # all paths start here, thus probability 1
    table.loc[startstate,:].iloc[0] = 1

    for i in range(1, table.shape[1]):
        for state_to in table.index:
            alternatives = []
            for state_from in table.index:
                alternatives.append(
                    (emissions[(state_to, table.columns[i])] if ((state_to, table.columns[i]) in emissions) else 0) *
                    (transitions[(state_from, state_to)] if ((state_from, state_to) in transitions) else 0) *
                    (table.loc[state_from,:].iloc[i-1] if i > 0 else 0)
                )
            table.loc[state_to,:].iloc[i] = h(alternatives)

    if (display_table):
        display(table)

    return h(table.iloc[:,-1])

def forward(inp, startstate, transitions, emissions, display_table:bool=False):
    return viterbi(inp, startstate, transitions, emissions, display_table, h=np.sum)
