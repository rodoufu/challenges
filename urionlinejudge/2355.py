while True:
	minutes = int(input().replace('\n', ''))
	if minutes == 0:
		break
	print(f"Brasil {minutes // 90} x Alemanha {7 * minutes // 90 + (1 if minutes % 90 > 0 else 0)}")
