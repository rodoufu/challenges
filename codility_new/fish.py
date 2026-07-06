# https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
def solution(A, B):
    count = 0

    fix_downstream = []

    for i in range(len(A)):
        going_up = B[i] == 0

        if not going_up:
            fix_downstream.append(A[i])
        else:
            while fix_downstream:
                if A[i] > fix_downstream[-1]:
                    fix_downstream.pop()
                else:
                    break
            if len(fix_downstream) == 0:
                count += 1

    return count + len(fix_downstream)
