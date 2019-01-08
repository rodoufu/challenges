#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter


# Complete the makeAnagram function below.
# https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=strings
def makeAnagram(a, b):
    ca = Counter(list(a))
    cb = Counter(list(b))
    ca.subtract(cb)
    return sum([abs(ca[x]) for x in ca])


if __name__ == '__main__':
    a = input()
    b = input()
    print(makeAnagram(a, b))
    # print(makeAnagram("cde", "abc"))
    # print(makeAnagram("fcrxzwscanmligyxyvym", "jxwtrhvujlmrpdoqbisbwhmgpmeoke"))
