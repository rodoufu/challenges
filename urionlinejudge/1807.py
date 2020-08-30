def mult_mod(a: int, b: int, n: int) -> int:
	return a % n * (b % n) % n


def exp_mod(a: int, b: int, n: int) -> int:
	if b == 0:
		return 1
	if b % 2 == 1:
		return mult_mod(exp_mod(a, b - 1, n), a, n)
	else:
		x = exp_mod(a, b // 2, n)
		return mult_mod(x, x, n)


r = int(input())
# print((3 ** r) % (2 ** 31 - 1))
print(exp_mod(3, r, 2 ** 31 - 1))

# Accepted
