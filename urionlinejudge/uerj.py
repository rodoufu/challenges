import math
import random
from typing import List, Iterable


def mult_mod_carr(a: int, b: int, n: int) -> int:
	r = 0
	while b:
		a %= n
		b >>= 1
		a = (a * 2) % n
		if b & 1:
			r = (r + a) % n
	return r


def fast_exp_mod(a: int, b: int, n: int) -> int:
	r = 1
	a %= n
	while b:
		a %= n
		b >>= 1
		a = (a * a) % n
		if b & 1:
			r = (r * a) % n
	return r


assert fast_exp_mod(479878, 45, 19) == 18


def mult_mod(a: int, b: int, n: int) -> int:
	return a % n * (b % n) % n


assert mult_mod(2000013, 12414000000017, 11) == 0
assert mult_mod(2000013, 12414000000019, 11) == 8


def exp_mod(a: int, b: int, n: int) -> int:
	if b == 0:
		return 1
	if b % 2 == 1:
		return mult_mod(exp_mod(a, b - 1, n), a, n)
	else:
		x = exp_mod(a, b // 2, n)
		return mult_mod(x, x, n)


assert exp_mod(479878, 45, 19) == 18


def fibonnaci_endless() -> Iterable[int]:
	a = b = 1
	yield a
	yield b
	while True:
		c = a + b
		a = b
		b = c
		yield c


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


assert erastotenes_crive(10) == [0, 1, 2, 3, 2, 5, 2, 7, 2, 3, 2]
assert erastotenes_crive(20) == [0, 1, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2, 13, 2, 3, 2, 17, 2, 19, 2]


def generate_primes(n: int, crive: List[int] = None) -> List[int]:
	if crive is None:
		crive = erastotenes_crive(n)
	primes = []
	for i in range(2, n + 1):
		if crive[i] == i:
			primes.append(i)

	return primes


assert generate_primes(10) == [2, 3, 5, 7]
assert generate_primes(20) == [2, 3, 5, 7, 11, 13, 17, 19]


def is_prime_10e3(n: int) -> bool:
	for i in range(2, int(math.sqrt(n)) + 1):
		if n % i == 0:
			return False
	return True


def is_prime_10e6(n: int, crive: List[int] = None) -> bool:
	if crive is None:
		crive = erastotenes_crive(n)
	return crive[n] == n


def is_prime_10e15(n: int, crive: List[int] = None, primes: List[int] = None) -> bool:
	if crive is not None and n + 1 <= len(crive):
		return crive[n] == n
	if primes is None:
		primes = generate_primes(n, crive)
	for prime in primes:
		if n % prime == 0:
			if n != prime:
				return False
			return True
	return True


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


def is_prime(n: int, crive: List[int] = None, primes: List[int] = None) -> bool:
	if crive is not None and n + 1 <= len(crive):
		return crive[n] == n
	if n <= int(10e3):
		return is_prime_10e3(n)
	elif n <= int(10e6):
		return is_prime_10e6(n, crive)
	elif n < int(10e7):
		return is_prime_10e6(n, crive)
	elif n < int(10e15):
		return is_prime_10e15(n, crive, primes)
	else:
		return is_prime_big(n)


assert is_prime(11)
assert is_prime(13)
assert is_prime_10e15(13)
assert is_prime_big(13)


def factor_10e3(n: int) -> List[int]:
	factors = []
	for i in range(2, int(math.sqrt(n)) + 1):
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


assert factor(50) == [2, 5, 5]
assert factor(121) == [11, 11]
assert factor_10e6(468) == [2, 2, 3, 3, 13]
assert factor_10e15(468) == [2, 2, 3, 3, 13]


def divisors(n: int, factors: List[int] = None) -> List[int]:
	if factors is None:
		factors = factor(n)
	factors = [1] + factors
	nf = len(factors)
	d = [1]
	nda = k = 0
	for i in range(1, nf):
		if factors[i] == factors[i - 1]:
			k *= factors[i]
		else:
			k = factors[i]
			nda = len(d)

		for j in range(nda):
			d.append(k * d[j])
	return d


assert divisors(50) == [1, 2, 5, 10, 25, 50]


def gdc(a: int, b: int) -> int:
	while b != 0:
		r = a % b
		a = b
		b = r
	return a


assert gdc(10, 25) == 5


def mmc(a: int, b: int) -> int:
	return a * b // gdc(a, b)


assert mmc(10, 25) == 50


def gdc_extended(a: int, b: int) -> (int, int, int):
	pa = []
	pb = []
	while b != 0:
		pa.append(a)
		pb.append(b)
		f = a % b
		a = b
		b = f
	x = 1
	y = 0
	for i in range(len(pa) - 1, -1, -1):
		f = y
		y = x - pa[i] // pb[i] * y
		x = f
	return a, x, y


assert gdc_extended(8, 6) == (2, 1, -1)
assert gdc_extended(99, 78) == (3, -11, 14)


def horner(num: str, n: int) -> int:
	len_num = len(num)
	m = 0
	for i in range(len_num - 1, -1, -1):
		m = ((m * 10) % n + int(num[i])) % n
	return m
