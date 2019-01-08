#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the alternatingCharacters function below.
def alternatingCharacters(s):
    count = 0
    letter = s[0]
    for i in range(1, len(s)):
        if s[i] == letter:
            count += 1
        else:
            letter = s[i]
    return count


if __name__ == '__main__':
    q = int(input())
    for q_itr in range(q):
        s = input()
        print(alternatingCharacters(s))
    # print(alternatingCharacters("AAAA"))
    # print(alternatingCharacters("BBBBB"))
    # print(alternatingCharacters("ABABABAB"))
    # print(alternatingCharacters("BABABA"))
    # print(alternatingCharacters("AAABBB"))
