#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the twoStrings function below.
def twoStrings(s1, s2):
	s1_hash = set()
	for x in s1:
		s1_hash.add(x)
	for x in s2:
		if x in s1_hash:
			return True
	return False


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	q = int(input())
	for q_itr in range(q):
		s1 = input()
		s2 = input()
		print('YES' if twoStrings(s1, s2) else 'NO')
		# fptr.write(result + '\n')
	# fptr.close()
