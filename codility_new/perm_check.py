# https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

def solution(A):
    if len(A) == 0:
        return 1
    size_a = len(A)
    max_a = max(A)
    if max_a != size_a:
        return 0
    A = set(A)
    if max_a == len(A) and 1 in A and size_a in A:
        return 1
    return 0
  
