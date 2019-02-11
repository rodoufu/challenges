def SimpleSymbols(str):
	lenS = len(str)
	if str[0].isalpha():
		return "false"
	for i in xrange(1, lenS):
		if str[i].isalpha() and (
			str[i - 1] != '+'
			or 	str[i + 1] != '+'):
			return "false"
	return "true"
    
# keep this function call here  
print SimpleSymbols(raw_input())
