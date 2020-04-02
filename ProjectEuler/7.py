# https://projecteuler.net/problem=7
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

	return [x for x in range(max_val) if crive[x]]


if __name__ == "__main__":
	value = int(math.sqrt(600851475143))
	primes = get_primes(value)
	count = 0
	while len(primes) < 10001:
		value *= 2
		print(f"Got {len(primes)} primes so far for value {value}")
		primes = get_primes(value)
		if count == 1:
			break
		count += 1
	print(f"Got {len(primes)} primes so far for value {value}")

	print(f"The prime is {primes[10000]}")
