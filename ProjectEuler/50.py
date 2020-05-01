# https://projecteuler.net/problem=50
import math


# def get_primes(max_val: int) -> set[int]:
def get_primes(max_val: int) -> list:
   crive = [True] * (max_val + 1)

   crive[0] = crive[1] = False
   for x in range(2, max_val + 1):
      if crive[x]:
         temp = x
         x += temp
         while x <= max_val:
            crive[x] = False
            x += temp

   # return {x for x in range(max_val) if crive[x]}
   return [x for x in range(max_val) if crive[x]]


if __name__ == "__main__":
   value = int(1e6)
   # primes = sorted(get_primes(int(math.sqrt(value))), reverse=True)
   primes = get_primes(value)
   primes_set = set(primes)
   primes_len = len(primes)
   consecutive = 1

   for i in range(primes_len):
      the_sum = primes[i]
      for j in range(i + 1, primes_len):
         the_sum += primes[j]
         if the_sum in primes_set and j - i > consecutive:
            consecutive = j - i
            print(f"New value {the_sum}, uses {consecutive}")
