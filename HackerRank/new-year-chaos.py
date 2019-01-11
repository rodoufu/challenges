#!/bin/python

import math
import os
import random
import re
import sys


# Complete the minimumBribes function below.
def doMinimumBribes(q):
	temp = [x for x in xrange(1, len(q) + 1)]
	cont = [0] * len(q)
	parar = False
	for i in xrange(len(q)):
		if parar:
			break
		while temp[i] != q[i]:
			indexOf = temp.index(q[i])
			temp[indexOf - 1], temp[indexOf] = temp[indexOf], temp[indexOf - 1]
			cont[q[i] - 1] += 1
			if cont[q[i] - 1] == 3:
				parar = True
				break
	print "Too chaotic" if parar else sum(cont)


def siteMinimumBribes(q):
	soma = 0
	for i in xrange(len(q) - 1, -1, -1):
		if q[i] - (i + 1) > 2:
			print("Too chaotic")
			return
		for j in xrange(max(0, q[i] - 2), i):
			soma += q[j] > q[i]
	print soma


def minimumBribes(q):
	diff = [q[i] - i - 1 for i in xrange(len(q))]
	print "Too chaotic" if max(diff) > 2 else sum([abs(x) for x in diff]) / 2


if __name__ == '__main__':
	t = int(raw_input())
	for t_itr in xrange(t):
		n = int(raw_input())
		q = map(int, raw_input().rstrip().split())
		minimumBribes(q)
