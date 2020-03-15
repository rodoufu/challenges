// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
class Solution {
public:
    string freqAlphabets(string s) {
        int len = s.size();
        if (!len)
            return "";
        string resp;
        int i;
        for (i = 0; i < len - 2; ++i) {
            //printf("i: %d = %c\n", i, s[i]);
            if (s[i + 2] == '#') {
                int incChar = 10 * (s[i] - '1') + s[i + 1] - '1' + 1;
                resp.push_back(static_cast<char>('j' + incChar));
                i += 2;
            } else {
                resp.push_back(static_cast<char>('a' + (s[i] - '1')));
            }
        }

        for (; i < len; ++i) {
            resp.push_back(static_cast<char>('a' + (s[i] - '1')));
        }

        return resp;
    }
};
