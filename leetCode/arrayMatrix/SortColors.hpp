//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unsigned red = count(nums.begin(), nums.end(), 0);
        unsigned white = count(nums.begin(), nums.end(), 1);
        unsigned blue = count(nums.begin(), nums.end(), 2);
        unsigned i = 0;
        for (; i < red; ++i) {
            nums[i] = 0;
        }
        for (; i < red + white; ++i) {
            nums[i] = 1;
        }
        for (; i < red + white + blue; ++i) {
            nums[i] = 2;
        }
    }
};
