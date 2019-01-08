#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict


# Complete the countTriplets function below.
# https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
def countTriplets(arr, r):
	count = 0
	t2 = defaultdict(int)
	t3 = defaultdict(int)
	for x in arr:
		count += t3[x]
		t3[x * r] += t2[x]
		t2[x * r] += 1

	return count


if __name__ == '__main__':
	nr = input().rstrip().split()
	n = int(nr[0])
	r = int(nr[1])
	arr = list(map(int, input().rstrip().split()))
	print(countTriplets(arr, r))
	#
	# print(countTriplets([1, 2, 2, 4], 2))
	# print(countTriplets([1, 3, 9, 9, 27, 81], 3))
	# print(countTriplets([1, 5, 5, 25, 125], 5))
	# print(countTriplets([1, 1, 1, 1, 1], 5))
	# print(countTriplets([1, 1, 1, 1, 1], 1))

	# Fail 2, 3, 6, 10, 11
