// https://leetcode.com/problems/sort-array-by-parity/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> resp;
        for (auto &x : A) {
            if (x % 2 == 0) {
                resp.push_back(x);
            }
        }
        for (auto &x : A) {
            if (x % 2 == 1) {
                resp.push_back(x);
            }
        }
        return resp;
    }
};
