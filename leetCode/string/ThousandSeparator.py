# https://leetcode.com/problems/thousand-separator/
class Solution:
    def thousandSeparator(self, n: int) -> str:
        if n == 0:
            return "0"
        
        value = []
        count = 0
        while n:
            value.append(str(n % 10))
            n //= 10
            count += 1
            if count % 3 == 0:
                value.append('.')
        
        if value[-1] == '.':
            value = value[:-1]
        
        return ''.join(value[::-1])
