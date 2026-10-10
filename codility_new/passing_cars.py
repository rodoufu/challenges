# https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/
def solution(A):
    ones_after_here = [0 for _ in range(len(A) + 1)]
    for x in A:
        if x == 1:
            ones_after_here[0] += 1
    
    for i in range(len(A)):
        if A[i] == 0:
            ones_after_here[i + 1] = ones_after_here[i]
        else:
            ones_after_here[i + 1] = ones_after_here[i] - 1
    resp = 0
    for i in range(len(A)):
        if A[i] == 0:
            resp += ones_after_here[i+1]
            if resp > 1_000_000_000:
                return -1
    return resp
