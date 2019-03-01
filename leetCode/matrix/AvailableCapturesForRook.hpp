//https://leetcode.com/problems/available-captures-for-rook
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int sizeI = board.size();
        if (!sizeI) {
            return 0;
        }
        int rook[2];
        rook[0] = -1;
        bool upper = false;
        int sizeJ = board[0].size();
        for (int i = 0; i < sizeI && rook[0] == -1; ++i) {
            for (int j = 0; j < sizeJ; ++j) {
                if (board[i][j] == 'r' || board[i][j] == 'R') {
                    upper = board[i][j] == 'R';
                    rook[0] = i;
                    rook[1] = j;
                    break;
                }
            }
        }
        int count = 0;
        for (int i = 1; i < 8 && rook[0] + i < 8; ++i) {
            char l = board[rook[0] + i][rook[1]]; 
            if (upper) {
                if (l == 'R' || l == 'B' || l == 'P') {
                    break;
                } else if (l == 'r' || l == 'b' || l == 'p') {
                    ++count;
                    break;
                }
            } else {
                if (l == 'r' || l == 'b' || l == 'p') {
                    ++count;
                    break;
                } else if (l == 'R' || l == 'B' || l == 'P') {
                    break;
                }
            }
        }
        
        for (int i = 1; i < 8 && rook[0] - i >= 0; ++i) {
            char l = board[rook[0] - i][rook[1]]; 
            if (upper) {
                if (l == 'R' || l == 'B' || l == 'P') {
                    break;
                } else if (l == 'r' || l == 'b' || l == 'p') {
                    ++count;
                    break;
                }
            } else {
                if (l == 'r' || l == 'b' || l == 'p') {
                    ++count;
                    break;
                } else if (l == 'R' || l == 'B' || l == 'P') {
                    break;
                }
            }
        }
        
        for (int i = 1; i < 8 && rook[1] + i < 8; ++i) {
            char l = board[rook[0]][rook[1] + i]; 
            if (upper) {
                if (l == 'R' || l == 'B' || l == 'P') {
                    break;
                } else if (l == 'r' || l == 'b' || l == 'p') {
                    ++count;
                    break;
                }
            } else {
                if (l == 'r' || l == 'b' || l == 'p') {
                    ++count;
                    break;
                } else if (l == 'R' || l == 'B' || l == 'P') {
                    break;
                }
            }
        }
        
        for (int i = 1; i < 8 && rook[1] - i >= 0; ++i) {
            char l = board[rook[0]][rook[1] - i]; 
            if (upper) {
                if (l == 'R' || l == 'B' || l == 'P') {
                    break;
                } else if (l == 'r' || l == 'b' || l == 'p') {
                    ++count;
                    break;
                }
            } else {
                if (l == 'r' || l == 'b' || l == 'p') {
                    ++count;
                    break;
                } else if (l == 'R' || l == 'B' || l == 'P') {
                    break;
                }
            }
        }

        return count;
    }
};
