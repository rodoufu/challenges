#!/bin/python

import math
import os
import random
import re
import sys


# Complete the repeatedString function below.
def repeatedString(s, n):
	lenS = len(s)
	return n / lenS * s.count('a') + s[:n % lenS].count('a')


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	s = raw_input()
	n = int(raw_input())
	result = repeatedString(s, n)
	print result
	# fptr.write(str(result) + '\n')
	# fptr.close()
