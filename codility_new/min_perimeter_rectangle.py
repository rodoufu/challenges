# https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/
import math

def solution(N):
    side = int(math.sqrt(N))
    if side * side == N:
        return 2 * (side + side)
    
    for i in range(side):
        if N % (side - i) == 0:
            a = side - i
            b = N // (side - i)
            # print(f"N: {N}, side: {side}, i: {i}, a: {a}, b: {b}")
            return 2 * (a + b)

    return 0
