//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> count;
        for (auto & it : A) {
            if (count.find(it) != count.end()) {
                return it;
            } else {
                count.emplace(it);
            }
        }
        return -1;
    }
};
