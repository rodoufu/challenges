# https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
def solution(A):
    count_numbers = {}
    for x in A:
        count_numbers[x] = count_numbers.get(x, 0) + 1
    
    for number, count in count_numbers.items():
        if count % 2 == 1:
            return number
    
    return 0
