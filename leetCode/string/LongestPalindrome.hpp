// https://leetcode.com/problems/longest-palindrome/
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
    int longestPalindrome(string s) {
        auto sumOne = 0;
        int size = 0;
        for (auto &x : count(s)) {
            if (x.second % 2 == 1) {
                sumOne = 1;
            }
            size += (x.second % 2 == 0) ? x.second : (x.second - 1);
        }
        
        return size + sumOne;
    }
};
