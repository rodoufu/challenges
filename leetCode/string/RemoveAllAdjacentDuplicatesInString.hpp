// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string S) {
        if (S.size() < 2) {
            return S;
        }

        int len = S.size();
        auto it = S.begin();
        while (S.size() > 1 && it + 1 != S.end()) {
            if (S.size() == 2 && S[0] == S[1]) {
                return "";
            }
            //printf("%c, %c, %s\n", *it, *(it + 1), S.c_str());
            if (*it == *(it + 1)) {
                auto temp = it == S.begin() ? it + 1 : it - 1;
                S.erase(it + 1);
                S.erase(it);
                it = temp;
            } else {
                ++it;
            }
        }
        
        if (len != S.size()) {
            return removeDuplicates(S);
        }
        return S;
    }
};
