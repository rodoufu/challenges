# https://projecteuler.net/problem=25
def fibonacci_digits(n):
   a = b = 1
   count = 2
   while len(str(b)) < n:
      t = a + b
      a = b
      b = t
      count += 1
   return count


if __name__ == "__main__":
   print(f"The index is {fibonacci_digits(1000)}")
