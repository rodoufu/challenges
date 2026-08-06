# https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
def solution(A):
    min_found = 100_000
    start_pos = 0
    prefix_sum = [0] * (len(A) + 1)
    for i in range(len(A)):
        prefix_sum[i + 1] = prefix_sum[i] + A[i]
    
    # print(f"prefix_sum: {prefix_sum}")
    for p in range(len(A)):
        for q in range(p + 1, min(len(A), p + 3)):
            # print(f"p: {p}, q: {q}")
            slice_value = (prefix_sum[q + 1] - prefix_sum[p]) / (q - p + 1)
            # print(f"p: {p}, q: {q},  slice_value: {slice_value}")
            if slice_value < min_found:
                # print(f"p: {p}, q: {q}, min_found: {min_found}, slice_value: {slice_value}, start_pos: {start_pos}")
                min_found = slice_value
                start_pos = p
    
    return start_pos
