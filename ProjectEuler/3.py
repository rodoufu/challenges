# https://projecteuler.net/problem=3
import math


# def get_primes(max_val: int) -> set[int]:
def get_primes(max_val: int) -> list:
	crive = [True] * (max_val + 1)

	crive[0] = crive[1] = False
	for x in range(2, max_val + 1):
		if crive[x]:
			temp = x
			x += temp
			while x <= max_val:
				crive[x] = False
				x += temp

	# return {x for x in range(max_val) if crive[x]}
	return [x for x in range(max_val) if crive[x]]


if __name__ == "__main__":
	value = 600851475143
	primes = sorted(get_primes(int(math.sqrt(value))), reverse=True)

	for prime in primes:
		if value % prime == 0:
			print(f"The biggest prime factor of {value} is {prime}")
			break
