// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> resp;
        for (int i = 0; i < n / 2; ++i) {
            resp.push_back(i + 1);
            resp.push_back(-i -1);
        }
        if (resp.size() != n) {
            resp.push_back(0);
        }
        return resp;
    }
};
