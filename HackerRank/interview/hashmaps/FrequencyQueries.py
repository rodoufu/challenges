#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict


# Complete the freqQuery function below.
# https://www.hackerrank.com/challenges/frequency-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
def freqQuery(queries):
    data = defaultdict(int)
    freq = defaultdict(int)
    for q in queries:
        if q[0] == 1:
            freq[data[q[1]]] = max(0, freq[data[q[1]]] - 1)
            data[q[1]] += 1
            freq[data[q[1]]] += 1
        elif q[0] == 2:
            if data[q[1]] > 0:
                freq[data[q[1]]] = max(0, freq[data[q[1]]] - 1)
                data[q[1]] -= 1
                freq[data[q[1]]] += 1
        else:
            yield 1 if freq[q[1]] > 0 else 0


if __name__ == '__main__':
    q = int(input().strip())
    queries = []
    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))
    print('\n'.join(map(str, freqQuery(queries))))
    # print([x for x in freqQuery([[1, 5], [1, 6], [3, 2], [1, 10], [1, 10], [1, 6], [2, 5], [3, 2]])])
    # print([x for x in freqQuery([[3, 4], [2, 1003], [1, 16], [3, 1]])])
    # print([x for x in freqQuery([[1, 3], [2, 3], [3, 2], [1, 4], [1, 5], [1, 5], [1, 4], [3, 2], [2, 4], [3, 2]])])
