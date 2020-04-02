# https://projecteuler.net/problem=4


# def get_primes(max_val: int) -> set[int]:
def is_palinddromic(val: int) -> bool:
	return str(val) == str(val)[::-1]


if __name__ == "__main__":
	largest = None
	for x in range(100, 999):
		for y in range(x, 999):
			if is_palinddromic(x * y):
				if largest is None or x * y > largest:
					largest = x * y
	print(f"The largest palindrome is {largest}")
