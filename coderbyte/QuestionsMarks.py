def QuestionsMarks(str):
	letras = list(str)
	anterior = None
	contInt = 0
	resp = "false"
	for letra in letras:
		if letra.isdigit():
			atual = ord(letra) - ord('0')
			if anterior is None:
				anterior = atual
			else:
				if anterior + atual == 10:
					if contInt == 3:
						resp = "true"
						# anterior = None
						anterior = atual
					else:
						return "false"
				else:
					anterior = None
			contInt = 0
		elif letra == "?":
			contInt += 1
	return resp
    
# keep this function call here  
print QuestionsMarks(raw_input())
