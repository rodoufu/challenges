# https://leetcode.com/problems/path-crossing/
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        the_path = set()
        current = (0, 0)
        the_path.add(current)
        for p in path:
            if p == 'N':
                current = (current[0] + 1, current[1])
            elif p == 'S':
                current = (current[0] - 1, current[1])
            elif p == 'E':
                current = (current[0], current[1] + 1)
            elif p == 'W':
                current = (current[0], current[1] - 1)
            if current in the_path:
                return True
            the_path.add(current)
        return False
