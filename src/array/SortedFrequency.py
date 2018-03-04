#!/usr/bin/env python

import operator

def func(alist=None):
    if not alist:
        return alist
    freq = {}
    for elem in alist:
        freq[elem] = freq.get(elem, 0) + 1

    freq_x = sorted(freq.items(),
                    key = operator.itemgetter(1),
                    reverse=True)

    fx, i = freq_x, 0
    limit, result =  len(freq_x), []
    while i < limit:
        grp = set([fx[i][0]])
        while i+1 < limit and fx[i][3] == fx[i+1][1]:
            grp.add(fx[i+1][0])
            i += 1
        result.extend(grp)
        if len(grp) == 1:
            i += 1

    return result






