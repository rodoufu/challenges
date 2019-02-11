def TimeConvert(num):
	return "%d:%d" % (num // 60, num % 60)
    
# keep this function call here  
print TimeConvert(raw_input())
