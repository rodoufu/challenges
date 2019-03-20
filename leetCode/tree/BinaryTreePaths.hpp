// https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return vector<string>();
        }
        vector<string> resp(binaryTreePaths(root->left));
        {
            auto right = binaryTreePaths(root->right);
            resp.insert(resp.end(), right.begin(), right.end());
        }
        int size = resp.size();
        for (int i = 0; i < size; ++i) {
            resp[i] = to_string(root->val) + "->" + resp[i];
        }
        if (!size) {
            resp.push_back(to_string(root->val));
        }
        
        return resp;
    }
};
