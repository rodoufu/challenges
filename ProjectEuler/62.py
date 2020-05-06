# https://projecteuler.net/problem=62
def count_digits(n):
   resp = {}
   for i in range(10):
      resp[i] = 0

   while n > 0:
      resp[n % 10] += 1
      n //= 10
   return resp


if __name__ == "__main__":
   the_smallest = 1
   i = 1
   the_numbers = {}
   while True:
      value = i ** 3
      the_digits = str(count_digits(value))
      if the_digits not in the_numbers:
         the_numbers[the_digits] = []
      the_numbers[the_digits] += [value]

      if len(the_numbers[the_digits]) == 5:
         the_smallest = min(the_numbers[the_digits])
         break
      i += 1

   print(f"The smallest is {the_smallest}")
