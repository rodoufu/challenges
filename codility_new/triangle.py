# https://app.codility.com/programmers/lessons/6-sorting/triangle/
def solution(A):
    A = sorted(A)
    for i in range(len(A)-2):
        if A[i] > A[i+2] - A[i+1]:
            return 1
    return 0
