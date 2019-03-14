// https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return 0;
        }
        for (int i = 1; i < size - 1; ++i) {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                return i;
            }
        }
        if (size > 1) {
            if (nums[size - 1] > nums[size - 2]) {
                return size - 1;
            }
            if (nums[0] > nums[1]) {
                return 0;
            }
            if (nums[size - 1] == nums[size - 2]) {
                return size - 1;
            }
            if (nums[0] == nums[1]) {
                return 0;
            }
        }
        return -1;
    }
};
