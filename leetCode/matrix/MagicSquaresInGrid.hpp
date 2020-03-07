// https://leetcode.com/problems/magic-squares-in-grid/
class Solution {
private:
    inline bool isMagic(vector<vector<int>>& grid, int x, int y, int size = 3) {
        {
            unordered_set<int> values;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (grid[x+i][y+j] < 1 || grid[x+i][y+j] > 9) {
                        return false;
                    }
                    if (values.find(grid[x+i][y+j]) != values.end()) {
                        return false;
                    }
                    values.emplace(grid[x+i][y+j]);
                }
            }
        }
        auto temp = 0;
        for (int i = 0; i < size; ++i) {
            temp += grid[x][y + i];
        }
        //printf("temp: %d\n", temp);
        
        auto t = 0;
        for (int i = 0; i < size; ++i) {
            t += grid[x + i][y + i];
        }
        if (t != temp) {
            return false;
        }
        
        t = 0;
        for (int i = 0; i < size; ++i) {
            t += grid[x + size - i - 1][y + i];
        }
        if (t != temp) {
            return false;
        }
        
        for (int i = 0; i < size; ++i) {
            t = 0;
            for (int j = 0; j < size; ++j) {
                t += grid[x + i][y + j];
            }
            if (t != temp) {
                return false;
            }
            
            t = 0;
            for (int j = 0; j < size; ++j) {
                t += grid[x + j][y + i];
            }
            if (t != temp) {
                return false;
            }
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int lenx = grid.size();
        if (!lenx) {
            return 0;
        }
        const int leny = grid[0].size();
        if (!leny) {
            return 0;
        }
        int counting = 0;
        const int size = 3;
        
        for (int i = 0; i < lenx - size + 1; ++i) {
            //printf("i: %d < %d\n", i, lenx - size + 1);
            for (int j = 0; j < leny - size + 1; ++j) {
                //printf("j: %d < %d\n", j, leny - size + 1);
                if (isMagic(grid, i, j, size)) {
                    ++counting;
                }
            }
        }
        
        return counting;
    }
};
