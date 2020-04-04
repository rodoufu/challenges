// https://leetcode.com/problems/detect-capital/
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) {
            return true;
        }
        int len = word.size();
        bool isUp = isupper(word[0]);
        if (isUp) {
            isUp = isupper(word[1]);
            if (isUp) {
                for (int i = 2; i < len; ++i) {
                    if (!isupper(word[i])) {
                        return false;
                    }
                }
            } else {
                for (int i = 2; i < len; ++i) {
                    if (isupper(word[i])) {
                        return false;
                    }
                }
            }
        } else {
            for (int i = 1; i < len; ++i) {
                if (isupper(word[i])) {
                    return false;
                }
            }
        }
        return true;
    }
};
