# https://projecteuler.net/problem=5


def is_divisible(val: int) -> bool:
	for x in range(5, 21):
		if val % x != 0:
			return False
	return True


if __name__ == "__main__":
	x = 2520 * 11 * 13 * 17 * 19
	while not is_divisible(x):
		x += 1
	print(f"The smallest divisible is {x}")
