//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> values;
        vector<int> resp;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (values.find(target - nums[i]) != values.end()) {
                resp.push_back(values[target - nums[i]]);
                resp.push_back(i);
                return resp;
            } else {
                values.emplace(nums[i], i);
            }
        }
        
        return resp;
    }
};
