#!/bin/python3

import math
import os
import random
import re
import sys

tripples_dict = dict()


# Complete the countTriplets function below.
def countTriplets(arr, r):
	# arr = sorted(arr)
	lena = len(arr)
	count = 0
	for i in range(lena):
		for j in range(i + 1, lena):
			if arr[j] // arr[i] == r:
				for k in range(j + 1, lena):
					count += 1 if arr[k] // arr[j] == r else 0
	return count


if __name__ == '__main__':
	nr = input().rstrip().split()
	n = int(nr[0])
	r = int(nr[1])
	arr = list(map(int, input().rstrip().split()))
	print(countTriplets(arr, r))

	# print(countTriplets([1, 2, 2, 4], 2))
	# print(countTriplets([1, 3, 9, 9, 27, 81], 3))
	# print(countTriplets([1, 5, 5, 25, 125], 5))
