# https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/
def solution(A, B, K):
    count_b = B // K
    count_a = (A - 1) // K
    return count_b - count_a
