def duplicate_encode(word):
	word = word.lower()
	return "".join(['(' if word.count(w) == 1 else ')' for w in word])


assert (duplicate_encode("din") == "(((")
assert (duplicate_encode("recede") == "()()()")
assert (duplicate_encode("Success") == ")())())")
assert (duplicate_encode("(( @") == "))((")
