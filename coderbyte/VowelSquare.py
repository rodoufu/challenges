def VowelSquare(strArr):
	lenStrArr = len(strArr)
	lenA = len(strArr[0])
	vogais = ["a", "e", "i", "o", "u"]
	#print(strArr)
	strArr = [x.lower() for x in strArr]
	#print(strArr)
	for i in xrange(lenStrArr - 1):
		for j in xrange(lenA - 1):
			if (strArr[i][j] in vogais) and (strArr[i][j + 1] in vogais) and (strArr[i + 1][j] in vogais) and (strArr[i + 1][j + 1] in vogais):
				return "%d-%d" % (i, j)
	return "not found"
    
# keep this function call here  
print VowelSquare(raw_input())
