//https://leetcode.com/problems/island-perimeter/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int sizeA = grid.size();
        if (sizeA == 0) {
            return 0;
        }
        const int sizeB = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < sizeA; ++i) {
            for (int j = 0; j < sizeB; ++j) {
                if (grid[i][j]) {
                    count += 4;
                    if (i > 0 && grid[i - 1][j]) {
                        --count;
                    }
                    if (i < sizeA - 1 && grid[i + 1][j]) {
                        --count;
                    }
                    
                    if (j > 0 && grid[i][j - 1]) {
                        --count;
                    }
                    if (j < sizeB - 1 && grid[i][j + 1]) {
                        --count;
                    }
                }
            }
        }
        
        return count;
    }
};
