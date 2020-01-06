// https://leetcode.com/problems/greatest-common-divisor-of-strings/
lass Solution {
private:
    unordered_map<string, unordered_map<int, string>> cache;
    string mult(string &str, int n) {
        if (cache.find(str) == cache.end()) {
            cache[str] = unordered_map<int, string>();
        } else if (cache[str].find(n) != cache[str].end()){
            return cache[str][n];
        }
        string resp;
        for (int i =0; i<n; ++i){
            resp += str;
        }
        return cache[str][n] = resp;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int s1=str1.size(), s2=str2.size();
        int p=0;
        int smn= s1 <s2? s1:s2;
        for (int i=1; i<=smn; ++i){
            if (s1%i==0 && s2% i==0){
                auto tk= str1.substr(0, i);
                if (str1 == mult(tk, s1 / i) && str2 ==mult(tk, s2 / i)){
                    p=i;
                }
            }
        }
        return str1.substr(0, p);
    }
};
