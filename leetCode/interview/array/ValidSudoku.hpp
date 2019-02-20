//https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> line;
        set<int> column;
        const int size = 9;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] != '.') {
                    if (line.find(board[i][j]) != line.end()) {
                        return false;
                    } else {
                        line.insert(board[i][j]);
                    }
                }
                if (board[j][i] != '.') {
                    if (column.find(board[j][i]) != column.end()) {
                        return false;
                    } else {
                        column.insert(board[j][i]);
                    }
                }
            }
            line.clear();
            column.clear();
        }
        
        int idi, idj;
        const int sub_size = 3;
        for (int i = 0; i < sub_size; ++i) {
            for (int j = 0; j < sub_size; ++j) {
                for (int k = 0; k < sub_size; ++k) {
                    for (int l = 0; l < sub_size; ++l) {
                        idi = i * sub_size + k;
                        idj = j * sub_size + l;
                        if (board[idi][idj] != '.') {
                            if (line.find(board[idi][idj]) != line.end()) {
                                return false;
                            } else {
                                line.insert(board[idi][idj]);
                            }
                        }
                    }
                }
                line.clear();
            }
        }
        
        return true;
    }
};
