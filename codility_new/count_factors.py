# https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/

def solution(N):
    i = 1
    count = 0
    while i * i < N:
        if N % i == 0:
            count += 2
        i += 1
    if i * i == N:
        count += 1
    return count
