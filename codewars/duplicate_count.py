def duplicate_count(text):
	text = text.lower()
	letras = set()
	repetidas = set()
	for t in text:
		if t in letras:
			repetidas.add(t)
		else:
			letras.add(t)
	return len(repetidas)


assert (duplicate_count("abcde") == 0)
assert (duplicate_count("abcdea") == 1)
assert (duplicate_count("indivisibility") == 1)
