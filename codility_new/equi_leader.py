# https://app.codility.com/programmers/lessons/8-leader/equi_leader/
def solution(A):
    stack_size = 0
    stack_value = 0
    for i in range(len(A)):
        x = A[i]
        if stack_size == 0:
            stack_size += 1
            stack_value = x
        elif x == stack_value:
            stack_size += 1
        elif x != stack_value:
            stack_size -= 1

    if stack_size == 0:
        return 0

    count = 0
    for x in A:
        if x == stack_value:
            count += 1
    
    if count <= len(A) / 2:
        return 0

    count_leader = [0] * (len(A) + 1)

    for i in range(1, len(A) + 1):
        count_leader[i] = count_leader[i - 1]
        if A[i - 1] == stack_value:
            count_leader[i] += 1

    equi_leaders = 0

    # print(f"count_leader: {count_leader}")
    for i in range(len(A) - 1):
        before = count_leader[i + 1]
        before_size = i + 1
        after = count_leader[len(A)] - count_leader[i + 1]
        after_size = len(A) - i - 1
        # print(f"i: {i}, before: {before}, before_size: {before_size}, after: {after}, after_size: {after_size}")
        if before <= before_size / 2:
            continue
        if after <=  after_size / 2:
            continue
        equi_leaders += 1
    
    return equi_leaders
