//https://leetcode.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int from = 0, to = nums.size() - 1;
        int it = (to + from) / 2;
        while (from <= to) {
            if (target == nums[it]) {
                return it;
            } else if (target < nums[it]) {
                to = it - 1;
            } else {
                from = it + 1;
            }
            it = (to + from) / 2;
        }
        return -1;
    }
};
