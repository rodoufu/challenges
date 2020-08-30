instances = int(input())

resp = {}
#        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
sticks = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
for x in sticks:
	resp[x] += 1


def count_numbers(num, before):
	if num == 0:
		return 0
	if num in resp:
		return resp[num]
	for i in range(len(sticks)):
		if (len(before) == 0 and i == 0) or sticks[i] > num:
			continue


for _ in range(instances):
	n = int(input())
