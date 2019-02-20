//https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> valores;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (valores.find(*it) != valores.end()) {
                return true;
            }
            valores.insert(*it);
        }
        return false;
    }
};
