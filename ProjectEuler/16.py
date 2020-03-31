# https://projecteuler.net/problem=16
a = 2 ** 1000
sum = 0
while a > 0:
  sum += a % 10
  a /= 10
sum
