# https://projecteuler.net/problem=56


def digit_sum(n):
   value = 0
   while n > 0:
      value += n % 10
      n //= 10
   return value


if __name__ == "__main__":
   n = 100
   the_max = 1
   for i in range(1, n):
      for j in range(1, n):
         ds = digit_sum(i ** j)
         if ds > the_max:
            the_max = ds
            print(f"The max is {the_max}")

   print(f"The max is {the_max}")
   
