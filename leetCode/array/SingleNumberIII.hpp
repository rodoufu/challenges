// https://leetcode.com/problems/single-number-iii/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> temp;
        for (auto & x : nums) {
            auto t = temp.find(x);
            if (t != temp.end()) {
                temp.erase(t);
            } else {
                temp.emplace(x);
            }
        }
        return vector<int>(temp.begin(), temp.end());
    }
};
