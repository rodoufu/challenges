class Solution:
	def twoSum(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[int]
		"""
		num_pos = dict()
		for i in range(len(nums)):
			num_pos[nums[i]] = num_pos.get(nums[i], [])
			num_pos[nums[i]].append(i)

		for i in range(len(nums)):
			diff = target - nums[i]
			if nums[i] == diff:
				if len(num_pos[nums[i]]) > 1:
					return [i, num_pos[nums[i]][1]]
			elif diff in num_pos:
				return [i, num_pos[diff][0]]

		return []


# print(Solution().twoSum([2, 7, 11, 15], 9))
print(Solution().twoSum([2, 5, 5, 11], 10))