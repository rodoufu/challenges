# https://leetcode.com/problems/rotate-string/
class Solution:
    def rotate(self, A: str, index: int) -> str:
        index = (index + len(A)) % len(A)
        return A[index:] + A[:index]

    def rotateString(self, A: str, B: str) -> bool:
        if A == B:
            return True
        if len(A) != len(B):
            return False

        positions = []
        lena = len(A)
        for i in range(lena):
            if B[i] == A[0]:
                positions.append(i)
        
        for p in positions:
            rotated = self.rotate(B, p)
            # print(f"rotated({p}): {rotated}")
            if rotated == A:
                return True
        
        return False
