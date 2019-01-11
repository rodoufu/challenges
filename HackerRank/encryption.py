#!/bin/python

import math
import os
import random
import re
import sys


# Complete the encryption function below.
def encryption(s):
	lenS = len(s)
	sqrtS = math.sqrt(lenS)
	rows = int(math.floor(sqrtS))
	columns = int(math.ceil(sqrtS))
	if rows * columns < lenS:
		rows += 1
	return " ".join(["".join([(s[i + j * columns] if i + j * columns < lenS else "") for j in xrange(rows)]) for i in xrange(columns)])


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	s = raw_input()
	result = encryption(s)
	print result
	# fptr.write(result + '\n')
	# fptr.close()
