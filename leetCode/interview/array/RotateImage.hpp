class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int size = matrix.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size / 2; ++j) {
                swap(matrix[i][j], matrix[i][size - j - 1]);
            }
        }
    }
};
