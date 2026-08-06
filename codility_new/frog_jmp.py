# https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
def solution(X, Y, D):
    distance = Y - X
    jumps = distance // D
    if distance % D == 0:
        return jumps
    else:
        return jumps + 1
