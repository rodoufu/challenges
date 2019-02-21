//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<tuple<TreeNode *, int> > nodes;
        nodes.push(make_tuple(root, 0));

        vector<vector<int>> values;
        if (root) {
            values.push_back(vector<int>());
            int height = 0;
            while (!nodes.empty()) {
                auto nodeSignal = nodes.front();
                nodes.pop();

                if (get<1>(nodeSignal) > height) {
                    values.push_back(vector<int>());
                    ++height;
                }
                auto node = get<0>(nodeSignal);
                values.back().push_back(node->val);

                if (node->left) {
                    nodes.push(make_tuple(node->left, height + 1));
                }
                if (node->right) {
                    nodes.push(make_tuple(node->right, height + 1));
                }
            }
        }

        return vector<vector<int>>(values.rbegin(), values.rend());
    }
};
