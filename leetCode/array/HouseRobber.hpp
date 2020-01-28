// https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() < 3) {
            return *max_element(nums.begin(), nums.end());
        }
        
        auto temp = vector<int>();
        temp.push_back(nums[0]);
        if (nums[1] > nums[0]) {
            temp.push_back(nums[1]);
        } else {
            temp.push_back(nums[0]);
        }
        
        for (int i = 2; i < nums.size(); ++i) {
            if (temp[temp.size() - 1] > temp[temp.size() - 2] + nums[i]) {
                temp.push_back(temp[temp.size() - 1]);
            } else {
                temp.push_back(temp[temp.size() - 2] + nums[i]);
            }
        }
        
        /*for (auto &x: temp) {
            printf("%d, ", x);
        }*/
        
        return temp[temp.size() - 1];
    }
};
