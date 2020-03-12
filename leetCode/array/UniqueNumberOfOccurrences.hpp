// https://leetcode.com/problems/unique-number-of-occurrences/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> num;
        for (auto &x : arr) {
            ++num[x];
        }
        unordered_set<int> occur;
        for (auto &[k, v] : num) {
            occur.emplace(v);
        }
        
        return num.size() == occur.size();
    }
};
