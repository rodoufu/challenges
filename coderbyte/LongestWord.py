def LongestWord(sen):
	palavras = sen.split(' ')
	maior = ""
	for palavra in palavras:
		atual = ""
		for letra in palavra:
			if letra.isalpha():
				atual += letra
		if len(atual) > len(maior):
			maior = atual
	return maior
    
# keep this function call here  
print LongestWord(raw_input())
