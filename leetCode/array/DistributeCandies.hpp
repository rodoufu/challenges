// https://leetcode.com/problems/distribute-candies/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kinds(candies.begin(), candies.end());
        return min(candies.size() / 2, kinds.size());
    }
};
