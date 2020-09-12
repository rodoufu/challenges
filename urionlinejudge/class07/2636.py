import math
from typing import List, Iterable


def erastotenes_crive(n: int) -> List[int]:
	C = [x for x in range(n + 1)]
	t = 2
	for i in range(1, n // 2 + 1):
		C[t] = 2
		t += 2
	for i in range(3, int(math.sqrt(n)) + 1):
		if C[i] == i:
			t = i * i
			d = i + i
			while t <= n:
				if C[t] == t:
					C[t] = i
				t += d
	return C


def generate_primes(n: int, crive: List[int] = None) -> List[int]:
	if crive is None:
		crive = erastotenes_crive(n)
	primes = []
	for i in range(2, n + 1):
		if crive[i] == i:
			primes.append(i)

	return primes


def factor_10e3(n: int, last: int = None) -> List[int]:
	factors = []
	if last is None:
		last = int(math.sqrt(n)) + 1
	for i in range(2, last):
		if n % i == 0:
			factors.append(i)
			n //= i

	if n > 1:
		factors.append(n)
	return factors


def factor_10e6(n: int, crive: List[int] = None) -> List[int]:
	factors = []
	if crive is None:
		crive = erastotenes_crive(n)
	while n != 1:
		factors.append(crive[n])
		n //= crive[n]
	return factors


def factor_10e15(n: int, primes: List[int] = None) -> List[int]:
	if primes is None:
		primes = generate_primes(n)
	factors = []
	for prime in primes:
		while n % prime == 0:
			factors.append(prime)
			n /= prime
		if n == 1 or prime >= int(math.sqrt(n)):
			break
	if n != 1:
		factors.append(n)
	return factors


def factor(n: int, crive: List[int] = None, primes: List[int] = None) -> List[int]:
	if n <= int(10e3):
		return factor_10e3(n)
	elif n <= int(10e6):
		return factor_10e6(n, crive)
	elif n <= int(10e15):
		return factor_10e15(n, primes)
	return []


while True:
	n = int(input().replace('\n', ''))
	if n == 0:
		break
	# primes = generate_primes(int(math.sqrt(min(n, int(3e7)))))
	# values = factor(n, primes=primes)

	# crive = erastotenes_crive(int(math.sqrt(min(n, int(3e7)))))
	# values = factor_10e6(n, crive=crive)

	# values = factor_10e6(n)
	values = factor_10e3(n, int(3e8))
	print(f"{n} = {values[0]} x {values[1]} x {values[2]}")

# Time limit exceeded
