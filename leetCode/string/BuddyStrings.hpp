//https://leetcode.com/problems/buddy-strings/
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        int diff = 0;
        int size = A.length();
        set<char> charA, charB;
        for (int i = 0; i < size; ++i) {
            if (A[i] != B[i]) {
                ++diff;
                charA.emplace(A[i]);
                charB.emplace(B[i]);
            }
        }
        if (!diff) {
            unordered_set<char> values;
            for (auto x : A) {
                if (values.find(x) != values.end()) {
                    return true;
                }
                values.emplace(x);
            }
        }
        return diff == 2 && charA == charB;
    }
};
