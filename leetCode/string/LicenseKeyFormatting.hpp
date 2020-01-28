// https://leetcode.com/problems/license-key-formatting/
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        auto resp = ""s;
        unsigned int count = 0;
        for (auto it = S.rbegin(); it != S.rend(); ++it) {
            if (isalnum(*it)) {
                resp.push_back(toupper(*it));
                ++count;
            }
            if (count == K) {
                resp.push_back('-');
                count = 0;
            }
        }
        if (resp.empty()) {
            return "";
        }
        return string(count ? resp.rbegin() : (resp.rbegin() + 1), resp.rend());
    }
};
