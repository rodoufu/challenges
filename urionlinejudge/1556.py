import sys


def plus_one(num):
	while True:
		i = 0
		plus = True
		while i < len(num) and plus:
			if num[i]:
				num[i] = False
			else:
				num[i] = True
				plus = False
			i += 1
		if plus:
			break
		yield num


def convert_word_count(word):
	n_word = []
	count = []
	for letter in word:
		if len(n_word) == 0 or letter != n_word[-1]:
			n_word.append(letter)
			count.append(1)
		else:
			count[-1] += 1
	return n_word, count


def gen_word(num, word):
	return ''.join([word[i] if num[i] else '' for i in range(len(num))])


def gen_multi_words(num, word, counts, idx=0):
	if idx == len(num):
		yield []
	else:
		if num[idx]:
			for c in range(1, counts[idx] + 1):
				value = [word[idx]] * c
				for it in gen_multi_words(num, word, counts, idx + 1):
					yield value + it
		else:
			for it in gen_multi_words(num, word, counts, idx + 1):
				yield it


def gen_words(word):
	words = set()
	word, counts = convert_word_count(word)
	for num in plus_one([False for _ in range(len(word))]):
		# new_word = gen_word(num, word)
		# new_word = gen_word(num, word)
		for new_word in gen_multi_words(num, word, counts):
			words.add("".join(new_word))
			# if new_word not in words:
			# 	words.add(new_word)
	return sorted(words)


# assert convert_word_count('aa') == (['a'], [2])
# assert convert_word_count('aababccc') == (['a', 'b', 'a', 'b', 'c'], [2, 1, 1, 1, 3])
# assert list(gen_multi_words([True, False, True], ['a', 'b', 'c'], [1, 1, 1], 0)) == [['a', 'c']]
# assert list(gen_multi_words([True, False, True], ['a', 'b', 'c'], [2, 1, 1], 0)) == [['a', 'c'], ['a', 'a', 'c']]
# assert list(gen_multi_words([True, False, True], ['a', 'b', 'c'], [2, 1, 2], 0)) == [
# 	['a', 'c'], ['a', 'c', 'c'],
# 	['a', 'a', 'c'], ['a', 'a', 'c', 'c'],
# ]

for line in sys.stdin:
	line = line.replace('\n', '')
	for word in gen_words(line):
		print(word)
	print("")
