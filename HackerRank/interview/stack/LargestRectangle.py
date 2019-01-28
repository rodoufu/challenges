#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the largestRectangle function below.
def largestRectangle(h):
	pilha = []
	h.append(0)
	lenh = len(h)
	area = lenh
	for i in range(lenh):
		li = i
		while pilha and pilha[-1][0] >= h[i]:
			last = pilha.pop()
			li = last[1]
			area = max(area, h[i] * (i + 1 - last[1]))
			area = max(area, last[0] * (i - last[1]))
		pilha.append((h[i], li))

	return area


if __name__ == '__main__':
	n = int(input())
	h = list(map(int, input().rstrip().split()))
	print(largestRectangle(h))
	# print(largestRectangle([1, 2, 3, 4, 5]))
