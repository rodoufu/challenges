#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the rotLeft function below.
def rotLeft(a, d):
	resp = [0 for x in range(len(a))]
	lena = len(a)
	for i in range(lena):
		resp[i] = a[(i + d) % lena]
	return resp


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	nd = input().split()
	n = int(nd[0])
	d = int(nd[1])
	a = list(map(int, input().rstrip().split()))
	print(" ".join(map(str, rotLeft(a, d))))
	# print(rotLeft([1, 2, 3, 4, 5], 4))
	# fptr.write(' '.join(map(str, result)))
	# fptr.write('\n')
	# fptr.close()
