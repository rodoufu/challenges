# https://projecteuler.net/problem=2
a = 1
b = 1
sum = 0
while b < 4000000L:
  r = a
  a = b
  b = r + a
  if b % 2 == 0:
    sum += b

>>> sum
