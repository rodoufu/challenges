def FirstFactorial(num):
	valor = num
	for i in xrange(1, num):
		valor *= i
	return valor
    
# keep this function call here  
print FirstFactorial(raw_input())
