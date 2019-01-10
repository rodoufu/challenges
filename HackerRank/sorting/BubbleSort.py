#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the countSwaps function below.
def countSwaps(a):
    enda = len(a) - 1
    unSorted = True
    swaps = 0
    while unSorted:
        unSorted = False
        for i in range(enda):
            if a[i] > a[i + 1]:
                unSorted = True
                a[i], a[i + 1] = a[i + 1], a[i]
                swaps += 1
    return swaps


def printResp(a):
    print(f'Array is sorted in {countSwaps(a)} swaps.')
    print(f'First Element: {a[0]}')
    print(f'Last Element: {a[-1]}')


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().rstrip().split()))
    printResp(a)
    # printResp([6, 4, 1])
    # printResp([1, 2, 3])
    # printResp([3, 2, 1])
