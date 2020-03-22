// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int lines = grid.size();
        if (!lines) {
            return 0;
        }
        int columns = grid[0].size();
        if (!columns) {
            return 0;
        }
        unordered_set<string> count;
        int maxLC = max(lines, columns);
        for (int k = maxLC - 1; k >= 0; --k) {
            if (k < columns) {
                for (int i = lines - 1; i >= 0; --i) {
                    if (grid[i][k] < 0) {
                        count.emplace(to_string(i) + ',' + to_string(k));
                    } else {
                        break;
                    }
                }
            }
            
            if (k < lines) {
                for (int i = columns - 1; i >= 0; --i) {
                    if (grid[k][i] < 0) {
                        count.emplace(to_string(k) + ',' + to_string(i));
                    } else {
                        break;
                    }
                }
            }
        }

        return count.size();
    }
};
