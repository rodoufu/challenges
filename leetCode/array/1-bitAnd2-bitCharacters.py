# https://leetcode.com/problems/1-bit-and-2-bit-characters/
class Solution:
    def ends_with_one_bit(self, bits: List[int], index: int) -> bool:
        remaining = len(bits) - index
        if remaining == 1:
            return True
        elif remaining == 2:
            return bits[-2] == 0
        
        if bits[index] == 0:
            # if if bits[index + 1] == 0:
            #     return False
            return self.ends_with_one_bit(bits, index + 1)
        else:
            return self.ends_with_one_bit(bits, index + 2)
        
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        return self.ends_with_one_bit(bits, 0)
