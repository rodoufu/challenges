# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # count_numbers = {}
        # for x in numbers:
        #     count_numbers[x] = count_numbers.get(x, 0) + 1
        
        # temp = []
        # for x, count in count_numbers.items():
        #     if count == 1:
        #         temp.append(x)
        #     else:
        #         temp.append(x)
        #         temp.append(x)
        # numbers = sorted(temp)
        # print(f"numbers: {numbers}")
        i = 0
        while i < len(numbers) - 1:
            j = i + 1
            while j < len(numbers):
                x = numbers[i] + numbers[j]
                if x == target:
                    return [i + 1, j + 1]

                if numbers[i] == numbers[j]:
                    i = j
                
                if x > target:
                    break
                j += 1
            i += 1

        return []
