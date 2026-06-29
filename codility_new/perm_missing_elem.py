# https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem
def solution(A):
    A = set(A)
    for i in range(1, len(A)+2):
        if i not in A:
            return i
    return 1
  
