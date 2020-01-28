// https://leetcode.com/problems/ransom-note/
class Solution {
private:
    inline unordered_map<char, int> count(const string &word) {
        auto resp = unordered_map<char, int>();
        for (auto &x : word) {
            resp[x]++;
        }
        return resp;
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        auto magazineCount = count(magazine);
        for (auto &x : count(ransomNote)) {
            auto val = magazineCount.find(x.first);
            if (val == magazineCount.end() || val->second < x.second) {
                return false;
            }
        }
        return true;
    }
};
