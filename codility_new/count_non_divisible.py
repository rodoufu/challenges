# https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible
import math

def solution(A):
    count_num = {}
    for x in A:
        count_num[x] = count_num.get(x, 0) + 1

    divisors_count = {}
    for num in count_num.keys():
        divisors_sum = 0
        limit = int(math.sqrt(num))

        for i in range(1, limit + 1):
            if num % i != 0:
                continue
            divisor1 = i
            divisor2 = num // i

            divisors_sum += count_num.get(divisor1, 0)
            if divisor1 != divisor2:
                divisors_sum += count_num.get(divisor2, 0)

        divisors_count[num] = divisors_sum
    
    return [len(A) - divisors_count.get(x, 0) for x in A]
