#!/bin/python3

import math
import os
import random
import re
import sys
import collections


# Complete the isValid function below.
def isValid(s):
    counter = list(collections.Counter(s).values())
    counter_set = set(counter)
    if len(counter_set) > 2:
        return False
    if len(counter_set) == 1:
        return True
    counter_set_list = list(counter_set)
    f0 = counter_set_list[0]
    f1 = counter_set_list[1]
    f0_count = counter.count(f0)
    f1_count = counter.count(f1)
    return (f0 == 1 and f0_count == 1) or \
           (f1 == 1 and f1_count == 1) or \
           (abs(f1 - f0) == 1 and (f0_count == 1 or f1_count == 1))


if __name__ == '__main__':
    s = input()
    print("YES" if isValid(s) else "NO")
    # assert not isValid('aabbcd')
    # assert not isValid('aabbccddeefghi')
    # assert isValid('abcdefghhgfedecba')
    # assert isValid('abcde')
    # assert isValid('a')
    # assert isValid('aabb')
    # assert isValid('aaaabbbbc')
    # assert not isValid('aaaabbbbcd')
    # assert not isValid('aabbcd')
    # assert not isValid('aaabbbcccde')
    # assert not isValid('aaaabbcc')
