# https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
def shift_right(A):
    if len(A) == 0:
        return
    previous = A[0]
    for i in range(1, len(A)):
        temp = A[i]
        A[i] = previous
        previous = temp
    A[0] = previous


def solution(A, K):
    if len(A) == 0 or K == len(A):
        return A
    K = K % len(A)
    for _ in range(K):
        shift_right(A)
    return A
  
