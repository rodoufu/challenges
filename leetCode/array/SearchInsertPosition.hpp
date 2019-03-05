//https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int m, left = 0, right = nums.size() - 1;

        while (left < right) {
            m = floor((left + right) / 2);
            //printf("[i:%d]=%d-l:%d,r:%d\n", m, nums[m], left, right);
            if (nums[m] < target) {
                left = m + 1;
            } else {
                right = m;
            }
        }
        return left == nums.size() - 1 ? (nums[left] >= target ? left : left + 1) : left;
    }
};
