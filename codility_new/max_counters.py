# https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

def solution(N, A):
    max_c = N + 1
    count_values = {}
    max_so_far = 0
    default_value = 0
    for command in A:
        if command == max_c:
            count_values.clear()
            default_value = max_so_far
        else:
            count_values[command] = count_values.get(command, default_value) + 1
            max_so_far = max(max_so_far, count_values[command])

    return [count_values.get(i+1, default_value) for i in range(N)]
