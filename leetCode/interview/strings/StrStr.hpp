//https://leetcode.com/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int lenh = haystack.length();
        int lenn = needle.length();
        
        if (lenh < lenn) {
            return -1;
        } else if (lenh == lenn) {
            return haystack == needle ? 0 : -1;
        }
        
        const char * ch = haystack.c_str();
        const char * cn = needle.c_str();
        for (int i = 0; i < lenh - lenn + 1; ++i) {
            if (ch[i] == cn[0]) {
                for (int j = 0; j < lenn; ++j) {
                    if (j == lenn - 1 && ch[i + j] == cn[j]) {
                        return i;
                    }
                    if (ch[i + j] != cn[j]) {
                        break;
                    }
                }
            }
        }
        
        return -1;
    }
};
