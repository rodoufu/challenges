import sys

for line in sys.stdin:
	moves = line.replace('\n', '').split(' ')
	has_winner = False
	for i in range(len(moves)):
		winner = True
		for j in range(len(moves)):
			if i == j:
				continue
			if moves[i] == moves[j]:
				winner = False
				break
		if winner:
			print(chr(ord('A') + i))
			has_winner = True
			break
	if not has_winner:
		print('*')
