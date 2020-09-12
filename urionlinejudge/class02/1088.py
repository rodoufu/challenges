def merge_sort(arr, l, r):
	if l < r:
		m = l + (r - l) // 2

		merge_sort(arr, l, m)
		merge_sort(arr, m + 1, r)

		merge(arr, l, m, r)


def merge(arr, l, m, r):
	n1 = m - l + 1
	n2 = r - m


# num = [1, 2]
# a = merge_sort(num)
# assert num == [1, 2]
# assert a == 0
# num = [2, 5, 7, 8, 10, 1, 3, 4, 6, 9]
# a = merge_sort(num)
# assert num == [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# assert a == 17
# assert merge_sort([1, 2]) == 0
# assert merge_sort([2, 5, 7, 8, 10, 1, 3, 4, 6, 9]) == 17

while True:
	nums = list(map(int, input().split(' ')))
	if nums[0] == 0:
		break
	nums = nums[1:]
	count = merge_sort(nums)
	if count % 2 == 0:
		print("Carlos")
	else:
		print("Marcelo")


# Time limit exceeded
