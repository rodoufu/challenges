# https://leetcode.com/problems/max-area-of-island/
class Solution:
    def island_area(self, grid: List[List[int]], x: int, y: int) -> int:
        if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]):
            return 0
        if grid[x][y] <= 0:
            return 0

        grid[x][y] = -1
        area = 1
        area += self.island_area(grid, x - 1, y)
        area += self.island_area(grid, x + 1, y)
        area += self.island_area(grid, x, y - 1)
        area += self.island_area(grid, x, y + 1)
        
        return area
        
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] <= 0:
                    continue
                
                area = self.island_area(grid, i, j)
                max_area = max(max_area, area)
        
        return max_area
