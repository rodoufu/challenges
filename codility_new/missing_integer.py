# https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/
def solution(A):
    A = sorted(filter(lambda x: x > 0, set(A)))
    if len(A) == 0 or A[0] != 1:
        return 1
    
    for i in range(1, len(A)):
        if A[i] != A[i-1] + 1:
            return A[i-1] + 1
    
    return A[-1] + 1
