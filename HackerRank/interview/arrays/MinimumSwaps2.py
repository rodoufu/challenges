#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the minimumSwaps function below.
def minimumSwaps(arr):
	actual = 0
	lena = len(arr)
	swaps = 0
	while actual < lena:
		if arr[actual] != actual + 1:
			temp = arr[actual]
			arr[actual] = arr[arr[actual] - 1]
			arr[temp - 1] = temp
			swaps += 1
		else:
			actual += 1
	return swaps


if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')
	n = int(input())
	arr = list(map(int, input().rstrip().split()))
	print(minimumSwaps(arr))
	# print(minimumSwaps([4, 3, 1, 2]))
	# print(minimumSwaps([4, 3, 2, 1]))
	# print(minimumSwaps([1, 5, 4, 3, 2]))
# fptr.write(str(res) + '\n')
# fptr.close()
