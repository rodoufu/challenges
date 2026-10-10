# https://app.codility.com/programmers/lessons/8-leader/dominator/
def solution(A):
    stack_size = 0
    stack_value = 0
    position = -1
    for i in range(len(A)):
        x = A[i]
        if stack_size == 0:
            stack_size += 1
            stack_value = x
            position = i
        elif x == stack_value:
            stack_size += 1
        elif x != stack_value:
            stack_size -= 1

    if stack_size == 0:
        return -1

    count = 0
    for x in A:
        if x == stack_value:
            count += 1
    
    if count > len(A) / 2:
        return position

    return -1
