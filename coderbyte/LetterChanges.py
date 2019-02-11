def LetterChanges(str):
	str = ''.join([
		(chr(ord('a') + (ord(letra) - ord('a') + 1) % 26) if letra.isalpha() else letra)
		for letra in str
	])
	return ''.join([
		letra.upper() if letra in "aeiou" else letra
		for letra in str
	])
    
# keep this function call here  
print LetterChanges(raw_input())
