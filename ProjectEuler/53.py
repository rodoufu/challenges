# https://projecteuler.net/problem=53
import operator as op
from functools import reduce


def ncr(n, r):
   r = min(r, n - r)
   numer = reduce(op.mul, range(n, n - r, -1), 1)
   denom = reduce(op.mul, range(1, r + 1), 1)
   return numer / denom


if __name__ == "__main__":
   n = 100
   count = 0
   for i in range(1, n + 1):
      for j in range(2, n):
         if ncr(i, j) > 1000000:
            count += 1
   print(f"The count is {count}")
   
