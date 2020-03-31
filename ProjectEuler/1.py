# https://projecteuler.net/problem=1
sum
for x in xrange(1, 1000):
  if x % 3 == 0 or x % 5 == 0:
    sum += x
sum
