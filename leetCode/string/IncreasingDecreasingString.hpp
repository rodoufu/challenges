// https://leetcode.com/problems/increasing-decreasing-string/
class Solution {
public:
    string sortString(string s) {
        map<char, int> letters;
        for (auto &x : s) {
            ++letters[x];
        }
        string resp;
        
        while(!letters.empty()) {
            if (letters.size() == 1) {
                auto it = letters.begin();
                resp += string(it->second, it->first);
                break;
            }
            
            set<char> toRemove;
            for (auto &[k, v] : letters) {
                if (v == 1) {
                    toRemove.emplace(k);
                }
                --v;
                resp.push_back(k);
            }
            
            for (auto &x : toRemove) {
                letters.erase(x);
            }
            toRemove.clear();
            
            for (auto it = letters.rbegin(); it != letters.rend(); ++it) {
                auto &k = it->first;
                auto &v = it->second;
                if (v == 1) {
                    toRemove.emplace(k);
                }
                --v;
                resp.push_back(k);
            }
            for (auto &x : toRemove) {
                letters.erase(x);
            }
        }
        return resp;
    }
};
