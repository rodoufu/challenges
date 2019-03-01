//https://leetcode.com/problems/third-maximum-number/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> values(nums.begin(), nums.end());
        if (values.size() > 2) {
            values.erase(max_element(values.begin(), values.end()));
            values.erase(max_element(values.begin(), values.end()));
        }
        return *max_element(values.begin(), values.end());;
    }
};
