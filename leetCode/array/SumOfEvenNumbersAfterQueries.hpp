// https://leetcode.com/problems/sum-of-even-numbers-after-queries/
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (auto &x : A) {
            if (x % 2 == 0) {
                sum += x;
            }
        }
        
        vector<int> resp;
        for (auto &x : queries) {
            if (A[x[1]] % 2 == 0) {
                sum -= A[x[1]];
            }
            A[x[1]] += x[0];
            if (A[x[1]] % 2 == 0) {
                sum += A[x[1]];
            }
            resp.push_back(sum);
        }
        return resp;
    }
};
