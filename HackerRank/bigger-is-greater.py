#!/bin/python

import math
import os
import random
import re
import sys


# Complete the biggerIsGreater function below.
def biggerIsGreater(w):
	w = list(w)
	for i in xrange(len(w) - 2, -1, -1):
		if w[i] < w[i + 1]:
			idx = i
			break
	if not idx:
		return "no answer"
	small = idx + 1
	for i in xrange(idx + 2, len(w)):
		if w[i] < w[small]:
			small = i
	if idx == small:
		return "no answer"
	w[idx], w[small] = w[small], w[idx]

	return "".join(w[:idx + 1] + sorted(w[idx + 1:]))


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	T = int(raw_input())

	for T_itr in xrange(T):
		w = raw_input()
		print biggerIsGreater(w)
	# fptr.write(result + '\n')

