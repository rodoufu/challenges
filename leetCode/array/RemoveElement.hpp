//https://leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (auto x : nums) {
            if (x == val) {
                count++;
            }
        }
        if (count == 0) {
            return nums.size();
        }
        int ini = 0, end = nums.size() - 1, c = 0;
        while (c < count && ini < end) {
            if (nums[ini] == val) {
                swap(nums[ini], nums[end--]);
            } else {
                ++ini;
            }
        }
        nums.resize(nums.size() - count);
        return nums.size();
    }
};
