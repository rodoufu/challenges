//https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size - 1; i++) {
            if (!nums[i]) {
                for (int j = i + 1; j < size; j++) {
                    if (nums[j]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};
