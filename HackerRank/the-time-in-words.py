#!/bin/python

import math
import os
import random
import re
import sys

numberName = ["o' clock", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
			  "ten", "eleven", "twoelve", "thirteen", "fourteen", "quarter",
			  "sixteen", "seventeen", "eighteen", "nineteen",
			  "twenty"]
numberName += ["twenty" + " " + numberName[i] for i in xrange(1, 10)]
numberName += ["half"]


# Complete the timeInWords function below.
def timeInWords(h, m):
	minutes = "minute{} ".format("s" if 1 < m < 59 else "") if m not in [15, 30, 45] else ""
	if m == 0:
		return "{} {}".format(numberName[h], numberName[m])
	elif m <= 30:
		return "{} {}past {}".format(numberName[m], minutes, numberName[h])
	else:
		return "{} {}to {}".format(numberName[60 - m], minutes, numberName[h + 1])


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	h = int(raw_input())
	m = int(raw_input())
	result = timeInWords(h, m)
	print result
	# fptr.write(result + '\n')
	# fptr.close()
