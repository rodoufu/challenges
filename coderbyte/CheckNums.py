def CheckNums(num1,num2):
	if num2 > num1:
		return "true"
	elif num1 > num2:
		return "false"
	else:
		return "-1"
    
# keep this function call here  
print CheckNums(raw_input())
