instances = int(input())

resp = {1: 0}
#        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
indexes = [1, 7, 4, 2, 3, 5, 0, 6, 9, 8]
sticks_ = [2, 3, 4, 5, 5, 5, 6, 6, 6, 7]


def count_numbers(num_i, nums=set(), carry_i=0):
	values = [(num_i, carry_i)]
	count = 0
	while values:
		num, carry = values[-1]
		values.pop()

		if num < 0:
			# return 0
			continue
		if num == 0:
			if carry in nums:
				# return 0
				continue
			else:
				nums.add(carry)
				# return 1
				count += 1
		if num in resp:
			return resp[num]
		for i in indexes:
			if i == 0 and carry == 0:
				continue
			if sticks_[i] > num:
				break
			values.append((num - sticks_[i], carry * 10 + i))
	resp[num] = count
	return resp[num]


for _ in range(instances):
	n = int(input())
	print(count_numbers(n))
