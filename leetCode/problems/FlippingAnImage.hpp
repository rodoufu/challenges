class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int sizeI = A.size();
        if (!sizeI) {
            return A;
        }
        int sizeJ = A[0].size();
        for (int i = 0; i < sizeI; ++i) {
            A[i] = vector<int>(A[i].rbegin(), A[i].rend());
        }
        for (int i = 0; i < sizeI; ++i) {
            for (int j = 0; j < sizeJ; ++j) {
                A[i][j] = A[i][j] != 1;
            }
        }
        return A;
    }
};
