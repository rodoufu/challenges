n = int(input())

for _ in range(n):
	blocks = list(map(int, input().replace('\n', '').split(' ')))
	blocks = [list(blocks[:3]), list(blocks[-3:])]
	resp = 0
	for i in range(len(blocks[0])):
		for j in range(len(blocks[0])):
			if i == j:
				continue
			for k in range(len(blocks[1])):
				for l in range(len(blocks[1])):
					if k == l:
						continue
					if blocks[0][i] < blocks[1][k] and blocks[0][j] < blocks[1][l]:
						resp |= 1
					if blocks[0][i] > blocks[1][k] and blocks[0][j] > blocks[1][l]:
						resp |= 2
	print(resp)
