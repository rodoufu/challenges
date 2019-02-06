class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<long long> prefixes = {0};
        for (int i = 0; i < size; ++i) {
            prefixes.push_back(max(prefixes[i] + nums[i], (long long) nums[i]));
        }
        return *max_element(prefixes.begin() + 1, prefixes.end());
    }
};
