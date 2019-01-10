#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the minimumAbsoluteDifference function below.
# https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
def minimumAbsoluteDifference(arr):
    arr = sorted(arr)
    lena = len(arr)
    diff = abs(arr[0] - arr[1])
    for i in range(1, lena - 1):
        if abs(arr[i] - arr[i + 1]) < diff:
            diff = abs(arr[i] - arr[i + 1])

    return diff


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    print(minimumAbsoluteDifference(arr))
    # print(minimumAbsoluteDifference([-2, 2, 4]))
    # print(minimumAbsoluteDifference([3, -7, 0]))
    # print(minimumAbsoluteDifference([-59, -36, -13, 1, -53, -92, -2, -96, -54, 75]))
    # print(minimumAbsoluteDifference([1, -3, 71, 68, 17]))
