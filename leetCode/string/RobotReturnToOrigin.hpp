// https://leetcode.com/problems/robot-return-to-origin/
class Solution {
public:
    bool judgeCircle(string moves) {
        int pos[] = {0, 0};
        int size = moves.length();
        for (int i = 0; i < size; ++i) {
            if (moves[i] == 'U') {
                ++pos[0];
            } else if (moves[i] == 'D') {
                --pos[0];
            } else if (moves[i] == 'R') {
                ++pos[1];
            } else if (moves[i] == 'L') {
                --pos[1];
            }
        }
        return pos[0] == pos[1] && pos[1] == 0;
    }
};
