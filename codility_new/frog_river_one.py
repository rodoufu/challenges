# https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
def solution(X, A):
    ocupied = set()
    for i in range(len(A)):
        if A[i] > 0 and A[i] <= X + 1:
            ocupied.add(A[i])
        if len(ocupied) == X:
            return i
    return -1
  
