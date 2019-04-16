// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size = s.length();
        if (size != t.length()) {
            return false;
        }
        if (!size) {
            return true;
        }
        unordered_map<char, char> values, inv;
        for (int i = 0; i < size; ++i) {
            auto it = values.find(s[i]);
            if (it != values.end() && it->second != t[i]) {
                return false;
            }
            it = inv.find(t[i]);
            if (it != values.end() && it->second != s[i]) {
                return false;
            }
            values[s[i]] = t[i];
            inv[t[i]] = s[i];
        }
        return true;
    }
};
