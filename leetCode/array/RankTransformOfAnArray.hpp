// https://leetcode.com/problems/rank-transform-of-an-array/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> cont;
        for (auto &x : arr) {
            cont.emplace(x);
        }
        int rankt = 0;
        unordered_map<int, int> rank;
        for (auto &x: cont) {
            rankt = rank[x] = rankt + 1;
        }
        
        vector<int> resp;
        for (auto &x : arr) {
            resp.push_back(rank[x]);
        }
        return resp;
    }
};
