# https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/

def solution(A):
    if len(A) == 0:
        return 0
    if len(A) == 1:
        return A[0]
    max_ending = A[0]
    max_slice = A[0]
    for i in range(1, len(A)):
        a = A[i]
        max_ending = max(a, max_ending + a)
        max_slice = max(max_slice, max_ending)
    return max_slice
