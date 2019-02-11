def LetterCapitalize(str):
	return " ".join([x[0].upper() + x[1:] for x in str.split(" ")])
    
# keep this function call here  
print LetterCapitalize(raw_input())
