# https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/

def solution(A):
    if len(A) == 0:
        return 0
    min_so_far = [A[0]] * (len(A) + 1)
    # max_so_far = [A[0]] * (len(A) + 1)

    for i in range(len(A)):
        min_so_far[i + 1] = min(min_so_far[i], A[i])
        # max_so_far[i + 1] = max(max_so_far[i], A[i])
    
    max_profit = 0
    for i in range(len(A)):
        max_profit = max(max_profit, A[i] - min_so_far[i + 1])

    return max_profit
