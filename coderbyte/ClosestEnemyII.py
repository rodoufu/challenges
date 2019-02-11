def ClosestEnemyII(strArr):
	heroi = None
	lenStrArr = len(strArr)
	lenA = len(strArr[0])
	inimigos = []
	for i in xrange(lenStrArr):
		for j in xrange(lenA):
			if strArr[i][j] == "1":
				heroi = (i, j)
			elif strArr[i][j] == "2":
				inimigos.append((i, j))
	if not inimigos:
		return "0"
	menor = lenA + lenStrArr
	for eni in inimigos:
		menor = min(menor, min(abs(heroi[0] - eni[0]), heroi[0] + lenA - eni[0]) + min(abs(heroi[1] - eni[1]), heroi[1] + lenStrArr - eni[1]))
	return menor
    
# keep this function call here  
print ClosestEnemyII(raw_input())
