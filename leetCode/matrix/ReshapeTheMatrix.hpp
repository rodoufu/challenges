// https://leetcode.com/problems/reshape-the-matrix/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() == 0 || nums[0].size() == 0 || r * c != nums.size() * nums[0].size()) {
            return nums;
        }
        
        vector<vector<int>> resp;
        int sizeI = nums.size(), sizeJ = nums[0].size(), collumn = 0, line = -1;
        for (int i = 0; i < sizeI; ++i) {
            for (int j = 0; j < sizeJ; ++j) {
                if (!collumn) {
                    resp.push_back(vector<int>());
                    ++line;
                }
                resp[line].push_back(nums[i][j]);

                collumn = (collumn + 1) % c;
            }
        }
        return resp;
    }
};
