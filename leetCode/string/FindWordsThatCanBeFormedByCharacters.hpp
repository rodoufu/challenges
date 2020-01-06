https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
class Solution {
private:
    unordered_map<char, int> count(string a){
        unordered_map<char, int> rp;
        for (auto &x: a){
            if (rp.find(x) == rp.end()) {
                rp[x] =0;
            }
            rp[x]++;
        }
        return rp;
    }
    int count(string a, unordered_map<char, int> &rf){
        unordered_map<char, int> r;
        for (auto &x: a){
            if (r.find(x) == r.end()){
                r[x]=0;
            }
            r[x]++;
            if (r[x] >rf[x]) 
                return 0;
        }
        return a.length();
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int c=0;
        auto ref = count(chars);
        for (auto &x : words){
            c += count(x, ref);
        }
        return c;
    }
};
