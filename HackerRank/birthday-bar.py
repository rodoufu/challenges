#!/bin/python

import math
import os
import random
import re
import sys


# Complete the birthday function below.
def birthday(v, d, m):
	s = [0] * (len(v) + 1)
	for i in xrange(len(v)):
		s[i + 1] = s[i] + v[i]
	contados = 0
	for i in xrange(len(v) - m + 1):
		if s[i + m] - s[i] == d:
			contados += 1
	return contados


if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')
	n = int(raw_input().strip())
	s = map(int, raw_input().rstrip().split())
	dm = raw_input().rstrip().split()
	d = int(dm[0])
	m = int(dm[1])
	result = birthday(s, d, m)
	fptr.write(str(result) + '\n')
	fptr.close()


# 2
# print birthday([1, 2, 1, 3, 2], 3, 2)
# # 0
# print birthday([1, 1, 1, 1, 1, 1], 3, 2)
# # 1
# print birthday([4], 4, 1)
# 
# print birthday([1, 1, 1, 1, 1, 1, 1, 1], 4, 2)
# 
# print birthday([1, 1, 1, 1, 1, 1, 1, 1], 4, 3)
# 
# print birthday([1, 1, 1, 1, 1, 1, 1, 1], 4, 4)
# 
# print birthday([1, 1, 1, 1, 1, 1, 1, 1], 4, 5)
