//https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> values;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (values.find(nums[i]) == values.end()) {
                values[nums[i]] = 0;
            }
            ++values[nums[i]];
            if (values[nums[i]] > size / 2) {
                return nums[i];
            }
        }
        return 0;
    }
};
