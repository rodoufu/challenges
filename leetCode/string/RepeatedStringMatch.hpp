// https://leetcode.com/problems/repeated-string-match/
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string all;
        int count = 0;
        while (all.length() < B.length()) {
            all += A;
            ++count;
        }
        for (int i = 0; i < 10 && all.find(B) == string::npos; ++i) {
            all += A;
            ++count;
        }
        //printf("c:%d - %s\n", count, all.c_str());
        return all.find(B) != string::npos ? count : -1;
    }
};
