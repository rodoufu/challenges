# https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
def solution(A):
    if len(A) == 0:
        return 0
    prefix_sum = [0] * (len(A) + 1)
    for i in range(len(A)):
        prefix_sum[i+1] = prefix_sum[i] + A[i]
    min_so_far = sum([abs(x) for x in A])
    # print(f"         A: {A}")
    # print(f"prefix_sum: {prefix_sum}")

    for i in range(len(A) - 1):
        # print(f"i: {i}")
        left = prefix_sum[i + 1]
        right = prefix_sum[len(A)] - prefix_sum[i + 1]
        cur_diff = left - right
        # print(f"i:{i}, min_so_far: {min_so_far}, left: {left}, right: {right}, curr_diff: {cur_diff}")
        min_so_far = min(min_so_far, abs(cur_diff))
    
    return min_so_far
