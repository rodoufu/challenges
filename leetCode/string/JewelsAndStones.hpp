//https://leetcode.com/problems/jewels-and-stones/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels(J.begin(), J.end());
        int resp = 0;
        for (auto &x : S) {
            if (jewels.find(x) != jewels.end()) {
                ++resp;
            }
        }
        return resp;
    }
};
