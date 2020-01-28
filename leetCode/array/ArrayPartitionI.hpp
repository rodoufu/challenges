// https://leetcode.com/problems/array-partition-i/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int maximum = 0;
        for (int i = 0; i < len - 1; i += 2) {
            maximum += min(nums[i], nums[i + 1]);
        }
        return maximum;
    }
};
