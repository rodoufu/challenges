// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) {
            return vector<int>();
        }
        
        //vector<tuple<int, int>> lineMinMax;
        vector<int> lineMin;
        int lenX = matrix.size();
        for (int i = 0; i < lenX; ++i) {
            //lineMinMax.push_back(make_tuple(matrix[i][0], matrix[i][0]));
            lineMin.push_back(matrix[i][0]);
        }
        
        //vector<tuple<int, int>> colMinMax;
        vector<int> colMax;
        int lenY = matrix[0].size();
        for (int j = 0; j < lenY; ++j) {
            //colMinMax.push_back(make_tuple(matrix[0][j], matrix[0][j]));
            colMax.push_back(matrix[0][j]);
        }
        for (int i = 0; i < lenX; ++i) {
            for (int j = 0; j < lenY; ++j) {
                //auto &[lmin, lmax] = lineMinMax[i];
                auto &lmin = lineMin[i];
                //auto &[cmin, cmax] = colMinMax[j];
                auto &cmax = colMax[j];
                auto val = matrix[i][j];
                
                //lineMinMax[i] = make_tuple(min(lmin, val), max(lmax, val));
                lineMin[i] = min(lmin, val);
                //colMinMax[j] = make_tuple(min(cmin, val), max(cmax, val));
                colMax[j] = max(cmax, val);
            }
        }
        
        auto printLC = [](vector<tuple<int, int>>& ve, const char* name) {
            printf("%s: ", name);
            for (auto &x : ve) {
                printf("%2d-%2d ", get<0>(x), get<1>(x));
            }
            putchar('\n');
        };
        
        //printLC(lineMinMax, "line");
        //printLC(colMinMax, " col");
        
        vector<int> resp;
        for (int i = 0; i < lenX; ++i) {
            auto &lmin = lineMin[i];
            for (int j = 0; j < lenY; ++j) {
                auto &cmax = colMax[j];
                //printf("%2d - %2d/%2d ", matrix[i][j], get<0>(lineMinMax[i]), get<1>(colMinMax[j]));
                //if (matrix[i][j] == get<0>(lineMinMax[i]) && matrix[i][j] == get<1>(colMinMax[j])) {
                if (matrix[i][j] == lmin && matrix[i][j] == cmax) {
                    resp.push_back(matrix[i][j]);
                }
            }
            //putchar('\n');
        }
        return resp;
    }
};
