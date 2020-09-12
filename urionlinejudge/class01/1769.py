# solved
import sys

for line in sys.stdin:
	cpf = list(map(int, line.replace('.', '')[:9]))
	digits = list(map(int, line.replace('\n', '')[-2:]))

	first = (sum([cpf[i] * (i + 1) for i in range(len(cpf))]) % 11) % 10
	second = (sum([cpf[i] * (len(cpf) - i) for i in range(len(cpf))]) % 11) % 10

	if first == digits[0] and second == digits[1]:
		print("CPF valido")
	else:
		print("CPF invalido")
		# print(f"{first}-{second}")
