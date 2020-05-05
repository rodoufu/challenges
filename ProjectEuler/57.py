# https://projecteuler.net/problem=57
import fractions


if __name__ == "__main__":
   n = 1000
   count = 0
   a = fractions.Fraction(1, 1)
   b = fractions.Fraction(1, 2)
   for i in range(0, n):
      b = fractions.Fraction(1, b + 2)
      ab = a + b
      if len(str(ab.numerator)) > len(str(ab.denominator)):
         count += 1

   print(f"The count is {count}")
   
