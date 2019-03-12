// https://leetcode.com/problems/reverse-only-letters/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int size = S.length();
        if (!size) {
            return "";
        }
        bool letter[size];
        for (int i = 0; i < size; ++i) {
            letter[i] = isalpha(S[i]);
        }
        for (int i = 0, j = size - 1; i < j; ) {
            //printf("i:%d,j:%d\n", i, j);
            if (letter[i] && letter[j]) {
                swap(S[i++], S[j--]);
            } else if (letter[i]) {
                --j;
            } else if (letter[j]) {
                ++i;
            } else {
                ++i;
                --j;
            }
        }
        return S;
    }
};
