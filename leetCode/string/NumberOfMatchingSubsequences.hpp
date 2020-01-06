// https://leetcode.com/problems/number-of-matching-subsequences/
class Solution {
private:
    unordered_map<string, unordered_map<string, bool>> cache;
    bool isSubsequence(string s, string t) {
        if (cache.find(s) == cache.end())
            cache[s] = unordered_map<string, bool>();
        auto si = s.begin(), ti=t.begin();
        while (si != s.end() && ti!=t.end()){
            if (*si == *ti){
                ++si;
            }
            ++ti;
        }
        return cache[s][t] = si == s.end();
    }
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int count=0;
        unordered_map<string, int> wc;
        for (auto &x : words){
            if (wc.find(x) == wc.end())
                wc[x]=0;
            wc[x]++;
        }
        for (auto &x: wc){
            if (isSubsequence(x.first, S))
                count+= x.second;
        }
        return count;
    }
};
