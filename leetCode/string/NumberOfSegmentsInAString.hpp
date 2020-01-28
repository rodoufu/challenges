// https://leetcode.com/problems/number-of-segments-in-a-string/
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        for (int i = 1; i < len; ++i) {
            if (s[i] == ' ' && s[i - 1] != ' ') {
                ++count;
            }
        }
        if (s[len - 1] != ' ') {
            ++count;
        }
        return count;
    }
};
