#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
	jumps = 0
	lenc = len(c)
	actual = 0
	while actual < lenc:
		if actual + 2 < lenc and c[actual + 2] == 0:
			actual += 2
		else:
			actual += 1
		jumps += 1
	return jumps - 1


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	n = int(input())
	c = list(map(int, input().rstrip().split()))
	print(jumpingOnClouds(c))
	# fptr.write(str(result) + '\n')
	# fptr.close()
	# print(jumpingOnClouds([0, 0, 1, 0, 0, 1, 0]))
	# print(jumpingOnClouds([0, 0, 0, 0, 1, 0]))

