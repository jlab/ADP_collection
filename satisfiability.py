import itertools

def _is_literal_satisfied(assignment, literal):
    """Tests if a single literal is satisfied by the given assignment."""
    if literal == 'P':
        return assignment
    elif literal == 'N':
        return (not assignment)
    else:
        return False

def _is_clause_satisfied(assignment, clause):
    """Tests if the whole clause is satisfied by the given assignment.
       Note: literals are concatenated via OR
    """
    return any(map(lambda x: _is_literal_satisfied(*x), zip(assignment, clause)))

def satisfiability(formula):
    """Tests if a formula can be satisfied.
       If so, return according assignments.
    """
    clauses = formula.split('&')
    assert len(set(map(len, clauses))) == 1, "clauses have different lengths!"

    sat_assignments = []
    for assignment in itertools.product([True, False], repeat=len(clauses[0])):
        satisfied = all(map(lambda x: _is_clause_satisfied(assignment, x), clauses))
        if satisfied:
            sat_assignments.append(assignment)

    return sat_assignments
