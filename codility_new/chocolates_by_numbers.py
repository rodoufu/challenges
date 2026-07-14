# https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def solution(N, M):
    return (N * M // gcd(N, M)) // M
