// https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto si = s.begin(), ti=t.begin();
        while (si != s.end() && ti!=t.end()){
            if (*si == *ti){
                ++si;
            }
            ++ti;
        }
        return si == s.end();
    }
};
