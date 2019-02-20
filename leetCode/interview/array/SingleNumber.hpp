//https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = nums[0];
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it) {
            value ^= *it;
        }
        return value;
    }
};
