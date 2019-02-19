class Solution {
public:
    inline int surrounding(const vector<vector<int>>& M, unsigned i, unsigned j) {
        int resp = 0, count = 0;
        int sizeI = M.size(), sizeJ = M[0].size();

        if (i > 0) {
            if (j > 0) {
                resp += M[i - 1][j - 1];
                ++count;
            }
            resp += M[i - 1][j];
            ++count;
            if (j < sizeJ - 1) {
                resp += M[i - 1][j + 1];
                ++count;
            }
        }

        if (j > 0) {
            resp += M[i][j - 1];
            ++count;
        }
        resp += M[i][j];
        ++count;
        if (j < sizeJ - 1) {
            resp += M[i][j + 1];
            ++count;
        }
        
        if (i < sizeI - 1) {
            if (j > 0) {
                resp += M[i + 1][j - 1];
                ++count;
            }
            resp += M[i + 1][j];
            ++count;
            if (j < sizeJ - 1) {
                resp += M[i + 1][j + 1];
                ++count;
            }
        }

        
        return resp / count;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> resp;
        int sizeI = M.size(), sizeJ = M[0].size();
        for (int i = 0; i < sizeI; ++i) {
            resp.push_back(vector<int>());
            resp[i].insert(resp[i].end(), sizeJ, 0);
            for (int j = 0; j < sizeJ; ++j) {
                resp[i][j] = surrounding(M, i, j);
            }
        }

        return resp;
    }
};
