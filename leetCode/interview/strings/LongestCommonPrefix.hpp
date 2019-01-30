class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string resp;
        int len = strs.size();
        if (len == 0) {
            return resp;
        }
        int smallLen = strs[0].length();

        for (int i = 1; i < len; ++i) {
            smallLen = smallLen < strs[i].length() ? smallLen : strs[i].length();
        }

        char actual;
        for (int i = 0; i < smallLen; ++i) {
            actual = strs[0][i];
            for (int j = 1; j < len; ++j) {
                if (actual != strs[j][i]) {
                    return resp;
                }
            }
            resp += actual;
        }

        return resp;
    }
};
