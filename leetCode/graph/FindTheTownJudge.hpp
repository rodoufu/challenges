// https://leetcode.com/problems/find-the-town-judge/description/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int> > graph;

        for (auto &x : trust) {
            graph[x[0]].emplace(x[1]);
        }
        
        for (int i = 1; i <= N; ++i) {
            bool judge = graph.find(i) == graph.end();
            for (int j = 1; j <= N && judge; ++j) {
                if (i == j) {
                    continue;
                }
                judge = graph[j].find(i) != graph[j].end();
            }
            if (judge) {
                return i;
            }
        }

        return -1;
    }
};
