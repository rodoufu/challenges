//https://leetcode.com/problems/univalued-binary-tree/
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
    bool isUnivalTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return true;
        }
        if (root->right) {
            if (root->val != root->right->val) {
                return false;
            }
            if (!isUnivalTree(root->right)) {
                return false;
            }
        }
        if (root->left) {
            if (root->val != root->left->val) {
                return false;
            }
            if (!isUnivalTree(root->left)) {
                return false;
            }
        }
        return true;
    }
};
