# https://projecteuler.net/problem=55


def is_palindrome(n):
   return n == reverse_num(n)


def reverse_num(n):
   value = 0
   while n > 0:
      value = value * 10 + n % 10
      n //= 10
   return value


def is_lychrel(n, attempts=51):
   for _ in range(attempts):
      n += reverse_num(n)
      if is_palindrome(n):
         return False
   return True


if __name__ == "__main__":
   n = 10000
   count = 0
   for i in range(2, n + 1):
      if is_lychrel(i):
         count += 1
   print(f"The count is {count}")
