//https://leetcode.com/problems/shortest-distance-to-a-character/
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int size = S.length();
        vector<int> resp(size, 20000);
        for (int i = 0; i < size; ++i) {
            if (S[i] == C) {
                resp[i] = 0;
            }
        }
        for (int i = 0; i < size; ++i) {
            if (resp[i] == 0) {
                for (int j = i - 1; j >= 0; --j) {
                    if (resp[j + 1] + 1 > resp[j]) {
                        break;
                    }
                    resp[j] = resp[j + 1] + 1;
                }
                for (int j = i + 1; j < size; ++j) {
                    if (resp[j - 1] + 1 > resp[j]) {
                        break;
                    }
                    resp[j] = resp[j - 1] + 1;
                }
            }
        }
        return resp;
    }
};
