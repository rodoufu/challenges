//https://leetcode.com/problems/k-diff-pairs-in-an-array/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(), nums.end());
        set<tuple<int, int>> pairs;
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (abs(nums[i] - nums[j]) == k) {
                    pairs.insert(make_tuple(nums[i], nums[j]));
                }
            }
        }
        return pairs.size();
    }
};
