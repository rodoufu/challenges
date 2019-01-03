#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
	magazine_dit = dict()
	for x in magazine:
		magazine_dit[x] = magazine_dit.get(x, 0) + 1
	for x in note:
		if x not in magazine_dit or magazine_dit[x] == 0:
			return 'No'
		else:
			magazine_dit[x] -= 1
	return 'Yes'


if __name__ == '__main__':
	mn = input().split()
	m = int(mn[0])
	n = int(mn[1])
	magazine = input().rstrip().split()
	note = input().rstrip().split()
	print(checkMagazine(magazine, note))
	# print(checkMagazine(['give', 'me', 'one', 'grand', 'today', 'night'], ['give', 'one', 'grand', 'today']))
	# print(checkMagazine(['two times three is not four'], ['two times two is four']))
	# print(checkMagazine(['ive', 'got', 'a', 'lovely', 'bunch', 'of', 'coconuts'], ['ive', 'got', 'some', 'coconuts']))
