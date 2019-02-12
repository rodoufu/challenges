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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        if ((root->left && root->val <= root->left->val)
            || (root->right && root->val >= root->right->val)) {
            return false;
        }
        if (!isValidBST(root->left) || !isValidBST(root->right)) {
            return false;
        }
        if (root->left) {
            if (root->val <= maxVal(root->left)) {
                return false;
            }
        }
        if (root->right) {
            if (root->val >= minVal(root->right)) {
                return false;
            }
        }
        return true;
    }
    
    int minVal(TreeNode* root) {
        int minResp = root->val;
        if (root->left) {
            minResp = min(minResp, minVal(root->left));
        }
        if (root->right) {
            minResp = min(minResp, minVal(root->right));
        }
        return minResp;
    }
    
    int maxVal(TreeNode* root) {
        int minResp = root->val;
        if (root->left) {
            minResp = max(minResp, maxVal(root->left));
        }
        if (root->right) {
            minResp = max(minResp, maxVal(root->right));
        }
        return minResp;
    }
};
