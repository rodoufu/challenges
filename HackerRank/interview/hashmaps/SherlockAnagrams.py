#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the sherlockAndAnagrams function below.
def sherlockAndAnagrams(s):
	lens = len(s)
	anarams = 0
	s = [ord(x) - ord('a') for x in s]
	for k in range(1, lens):
		for i in range(lens - k):
			sik = sorted(s[i:i + k])
			for j in range(i + 1, lens - k + 1):
				sjk = sorted(s[j:j + k])
				# print(f'{i}, {j}, {k}: {sik} = {sjk}')
				anarams += 1 if sik == sjk else 0
	return anarams


if __name__ == '__main__':
	q = int(input())
	for q_itr in range(q):
		s = input()
		print(sherlockAndAnagrams(s))
	# print(sherlockAndAnagrams("abba"))
	# print(sherlockAndAnagrams("abcd"))
	# print(sherlockAndAnagrams("ifailuhkqq"))
	# print(sherlockAndAnagrams("kkkk"))
	# print(sherlockAndAnagrams("cdcd"))
