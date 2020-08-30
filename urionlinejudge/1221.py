import random


instances = int(input().replace('\n', ''))


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


def is_prime_big(p: int, attempts: int = 10) -> bool:
	if attempts > 0:
		for _ in range(attempts):
			a = random.randint(2, p)
			if exp_mod(a, p, p) != a % p:
				return False
	else:
		for a in range(2, p):
			if exp_mod(a, p, p) != a % p:
				return False
	return True


for _ in range(instances):
	num = int(input().replace('\n', ''))
	if is_prime_big(num):
		print("Prime")
	else:
		print("Not Prime")

# Accepted
