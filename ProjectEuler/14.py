# https://projecteuler.net/problem=14
def collatz_size(n):
   the_size = 0
   while n > 1:
      the_size += 1
      if n % 2 == 0:
         n /= 2
      else:
         n = 3 * n + 1
   return the_size


if __name__ == "__main__":
   longest_collatz = (1, 1)
   for i in range(2, 1000001):
      collatz_size_i = collatz_size(i)
      if collatz_size_i > longest_collatz[1]:
         longest_collatz = (i, collatz_size_i)
   print(f"The longest is {longest_collatz[0]}")
   
