//https://leetcode.com/problems/squares-of-a-sorted-array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> resp;
        for (auto & it : A) {
            resp.push_back(it * it);
        }
        sort(resp.begin(), resp.end());
        return resp;
    }
};
