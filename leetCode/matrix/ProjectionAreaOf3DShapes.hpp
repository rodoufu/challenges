// https://leetcode.com/problems/projection-area-of-3d-shapes/
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int top = 0;
        for (auto &x : grid) {
            for (auto &y : x) {
                if (y) {
                    ++top;
                }
            }
            top += *max_element(x.begin(), x.end());
        }
        
        int sizeI = grid.size();
        if (!sizeI) {
            return 0;
        }
        int sizeJ = grid[0].size();
        int maior;
        for (int j = 0; j < sizeJ; ++j) {
            maior = 0;
            for (int i = 0; i < sizeI; ++i) {
                maior = max(maior, grid[i][j]);
            }
            top += maior;
        }
        
        return top;
    }
};
