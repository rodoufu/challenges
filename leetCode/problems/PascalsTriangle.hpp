//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> resp;
        if (numRows == 0) return resp;
        vector<int> vec={1};
        resp.push_back(vec);
        for (int i = 2; i <= numRows; ++i){
            vector<int> line;
            line.push_back(1);
            for (int j=0; j < i -2; ++j){
                line.push_back(resp[i-2][j] + resp[i-2][j+1]);
                }
            line.push_back(1);
            resp.push_back(line);
            }
        return resp;
    }
};
