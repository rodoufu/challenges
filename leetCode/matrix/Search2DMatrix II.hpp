// https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        for (auto &x : matrix) {
            int size = x.size();
            if (x[0] <= target && target <= x[size - 1] && binary_search(x.begin(), x.end(), target)) {
                return true;
            }
        }
        return false;
    }
};
