# https://projecteuler.net/problem=10
def sum_primes(N):
   primes = [it if it % 2 == 1 else 0 for it in range(1, N + 1)]
   for it in primes:
      if it > 2:
         i = 3
         while it * i <= N:
            primes[it * i - 1] = 0
            i += 1
      elif it > N // 3:
         break
   return sum(primes) + 1


if __name__ == "__main__":
   print(f"The sum is {sum_primes(2000000)}")
