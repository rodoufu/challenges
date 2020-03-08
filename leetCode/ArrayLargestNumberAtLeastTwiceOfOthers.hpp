// https://leetcode.com/problems/largest-number-at-least-twice-of-others
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxI = 0;
        int len = nums.size();
        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[maxI]) {
                maxI = i;
            }
        }
        
        int max2 = -1;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != nums[maxI] && nums[i] > max2) {
                max2 = nums[i];
            }
        }
        
        //printf("%d-%d\n", nums[maxI], max2);
        if (nums[maxI] >= 2 * max2) {
            return maxI;
        }
        return -1;
    }
};
