// https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> resp;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                resp.push_back(nums[i]);
            }
        }
        return resp;
    }
};
