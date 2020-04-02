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
private:
    int sumTree(TreeNode* node, int val) {
        if (!node) {
            return 0;
        }
        int resp = sumTree(node->left, val * 2 + node->val) + sumTree(node->right, val * 2 + node->val);
        if (!resp) {
            return val * 2 + node->val;
        }
        return resp;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return sumTree(root, 0);
    }
};
