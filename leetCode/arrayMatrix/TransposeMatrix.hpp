//https://leetcode.com/problems/transpose-matrix/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int sizeI = A.size();
        if (sizeI == 0) {
            return A;
        }
        int sizeJ = A[0].size();

        vector<vector<int>> resp;
        for (int j = 0; j < sizeJ; ++j) {
            resp.push_back(vector<int>());
            for (int i = 0; i < sizeI; ++i) {
                resp[j].push_back(A[i][j]);
                //printf("%d ", A[i][j]);
            }
            //printf("\n");
        }
        
        return resp;
    }
};
