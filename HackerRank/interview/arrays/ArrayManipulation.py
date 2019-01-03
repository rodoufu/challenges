#!/bin/python3
#https://www.hackerrank.com/challenges/crush/problem

import math
import os
import random
import re
import sys


# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
	arr = [0 for _ in range(n + 1)]
	for x in queries:
		arr[x[0] - 1] += x[2]
		arr[x[1]] -= x[2]
	sum = 0
	maxi = 0
	for x in arr:
		sum += x
		maxi = max(maxi, sum)
	return maxi


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	nm = input().split()
	n = int(nm[0])
	m = int(nm[1])
	queries = []
	for _ in range(m):
		queries.append(list(map(int, input().rstrip().split())))
	print(arrayManipulation(n, queries))
	# print(arrayManipulation(5, [[1, 2, 100], [2, 5, 100], [3, 4, 100]]))
# fptr.write(str(result) + '\n')
# fptr.close()
