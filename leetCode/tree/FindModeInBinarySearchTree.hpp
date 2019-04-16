// https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    vector<int> findMode(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        unordered_map<int, int> counter;
        stack<TreeNode*> values;
        values.push(root);
        int biggest = 0;
        while (!values.empty()) {
            auto node = values.top();
            values.pop();
            biggest = max(biggest, ++counter[node->val]);
            if (node->left) {
                values.push(node->left);
            }
            if (node->right) {
                values.push(node->right);
            }
        }
        
        vector<int> resp;
        for (auto &x : counter) {
            if (x.second == biggest) {
                resp.push_back(x.first);
            }
        }
        return resp;
    }
};
