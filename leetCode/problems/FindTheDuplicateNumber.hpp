class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};
