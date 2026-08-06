# https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
def solution(A):
    if len(A) == 3:
        return A[0] * A[1] * A[2]

    n_nums = sorted(filter(lambda x: x < 0, A))
    p_nums = sorted(filter(lambda x: x >= 0, A))

    if len(p_nums) == 0:
        return n_nums[-3] * n_nums[-2] * n_nums[-1]
    if len(p_nums) == 1:
        return p_nums[0] * n_nums[0] * n_nums[1]
    if len(p_nums) == 2:
        max_so_far = p_nums[0] * p_nums[1] * n_nums[-1]
    else:
        max_so_far = p_nums[-1] * p_nums[-2] * p_nums[-3]
        
    if len(n_nums) >= 2:
        max_so_far = max(max_so_far, p_nums[-1] * n_nums[0] * n_nums[1])

    return max_so_far
