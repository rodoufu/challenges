#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the countingValleys function below.
def countingValleys(n, s):
	high = 0
	path = []
	for x in s:
		path += [high]
		if x == 'U':
			high += 1
		else:
			high -= 1
	high = path[0]
	cont = 0
	for i in range(1, len(path)):
		if path[i] < 0 and high == 0:
			cont += 1
		high = path[i]
	return cont


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	n = int(input())
	s = input()
	print(countingValleys(n, s))

	# fptr.write(str(result) + '\n')
	# fptr.close()
