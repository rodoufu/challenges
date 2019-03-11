// https://leetcode.com/problems/average-of-levels-in-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        stack<tuple<TreeNode *, int> > nodes;
        nodes.push(make_tuple(root, 0));
        unordered_map<int, tuple<double, int>> levelAverage;
        int levels = 0;
        while (!nodes.empty()) {
            auto value = nodes.top();
            nodes.pop();
            auto node = get<0>(value);
            auto level = get<1>(value);
            if (node->left) {
                nodes.push(make_tuple(node->left, level + 1));
            }
            if (node->right) {
                nodes.push(make_tuple(node->right, level + 1));
            }
            
            if (levelAverage.find(level) == levelAverage.end()) {
                levelAverage[level] = make_tuple(0, 0);
            }
            auto actual = levelAverage[level];
            levelAverage[level] = make_tuple(get<0>(actual) + node->val, get<1>(actual) + 1);
            levels = max(levels, level + 1);
        }
        auto resp = vector<double>();
        for (int i = 0; i < levels; ++i) {
            resp.push_back(0);
        }
        for (auto it : levelAverage) {
            resp[it.first] = get<0>(it.second) / get<1>(it.second);
        }

        return resp;
    }
};
