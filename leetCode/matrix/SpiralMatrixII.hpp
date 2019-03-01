//https://leetcode.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const int n2 = n * n;
        short direction = 0;
        int minI = 0, maxI = n, minJ = 0, maxJ = n;

        vector<vector<int>> resp;
        for (int i = 0; i < n; ++i) {
            vector<int> it;
            for (int j = 0; j < n; ++j) {
                it.push_back(0);
            }
            resp.push_back(it);
        }

        bool incI, decI, incJ, decJ;
        for (int i = 0, j = 0, cont = 1; cont <= n2; ++cont) {
            incI = decI = incJ = decJ = false;
            //printf("i:%d,j:%d,cont:%d,direction:%d,minI:%d,maxI:%d,minJ:%d,maxJ:%d\n", i, j, cont, direction, minI, maxI, minJ, maxJ);

            resp[i][j] = cont;
            incJ = direction == 0;
            incI = direction == 1;
            decJ = direction == 2;
            decI = direction == 3;

            if (direction == 0 && j == maxJ - 1) {
                --maxJ;
                incJ = false;
                incI = true;
                direction = (direction + 1) % 4;
            } else if (direction == 1 && i == maxI - 1) {
                --maxI;
                incI = false;
                decJ = true;
                direction = (direction + 1) % 4;
            } else if (direction == 2 && j == minJ) {
                ++minJ;
                decJ = false;
                decI = true;
                direction = (direction + 1) % 4;
            } else if (direction == 3 && i == minI + 1) {
               ++minI;
                decI = false;
                incJ = true;
                direction = (direction + 1) % 4;
            }
            
            i += incI ? 1 : 0;
            j += incJ ? 1 : 0;
            i -= decI ? 1 : 0;
            j -= decJ ? 1 : 0;
            //printf("i:%d,j:%d,cont:%d,direction:%d,minI:%d,maxI:%d,minJ:%d,maxJ:%d-\n", i, j, cont, direction, minI, maxI, minJ, maxJ);
        }

        return resp;
    }
};
