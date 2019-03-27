// https://leetcode.com/problems/di-string-match/
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> resp;
        int low = 0, high = S.length();
        for (auto & x : S) {
            if (x == 'I') {
                resp.push_back(low++);
            } else {
                resp.push_back(high--);
            }
        }
        resp.push_back(low);
        return resp;
    }
};
