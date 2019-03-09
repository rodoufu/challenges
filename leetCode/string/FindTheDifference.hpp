//https://leetcode.com/problems/find-the-difference/
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> v;
        for (auto x : t) {
            if(v.find(x)!=v.end()){
                ++v[x];
             } else{
                v[x]=1;
             }
        }
        
        for (auto x:s){
            --v[x];
            if (!v[x]){
                v.erase(v.find(x));
            }
        }
        return v.begin()->first;
    }
};
