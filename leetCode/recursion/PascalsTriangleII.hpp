//https://leetcode.com/problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        queue<vector<int>> resp;
        resp.push({1});
        resp.push({1, 1});

        for (int cont = 2; cont <= rowIndex; ++cont) {
            resp.pop();
            vector<int> line = {1};
            
            vector<int> &tempLine = resp.back();
            int size = tempLine.size();
            for (int i = 1; i < size; ++i) {
                line.push_back(tempLine[i] + tempLine[i - 1]);
            }
            
            line.push_back(1);
            resp.push(line);
        }
        return rowIndex == 0 ? resp.front() : resp.back();
    }
};
