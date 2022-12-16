import pandas as pd
import numpy as np
import itertools

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
    states = sorted(list(set(sum([list(k) for k in transitions.keys()], []))))
    states_with_emissions = set([s for (s,_) in emissions.keys()])

    # sanity checks
    assert startstate in states, "start-state not in list of states!"
    # make startstate first in list
    states = [startstate] + [s for s in states if s != startstate]
    #assert set(states) == set(map(lambda x: x[0], emissions.keys())), "emission and transition states do not match!"
    assert len(states_with_emissions - set(states)) == 0, "some of your emitting states lack transitions!"

    # check if probabilistic assumptions hold
    errors = []
    for state in states:
        probsum_outgoing = sum([prob for (transition, prob) in transitions.items() if transition[0] == state])
        if probsum_outgoing != 1.0:
            errors.append("Outgoing transition probabilities for state '%s' do not add up to 1.0, but to %.2f" % (state, probsum_outgoing))
        probsum_emission = sum([prob for (key, prob) in emissions.items() if key[0] == state])
        if (state in [s for (s,_) in emissions.keys()]) and (abs(probsum_emission - 1.0) > 0.0001):
            errors.append("Emission probabilities for state '%s' do not add up to 1.0, but to %.2f" % (state, probsum_emission))
    if len(errors) > 0:
        raise ValueError("Probabilistic assumptions violated!\n" + "\n".join(map(lambda x: "  - %s" %x, errors)))

    # add 1.0 emission probabilities to silent emissions for the non-input ε
    for state in set(states) - states_with_emissions:
        emissions[(state, 'ε')] = 1.0

    table = pd.DataFrame(index=states, columns=["ε"] + inp + ["ε"], data=0.0)

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

    # try to identify an end state and move to last row in table for better visual representation
    if sum(table.iloc[:, -1] != 0) == 1:
        endstate = table.index[table.iloc[:, -1] != 0][0]
        table = table.loc[[s for s in table.index if s != endstate] + [endstate], :]

    if (display_table):
        display(table)

    return h(table.iloc[:,-1])

def forward(inp, startstate, transitions, emissions, display_table:bool=False):
    return viterbi(inp, startstate, transitions, emissions, display_table, h=np.sum)
