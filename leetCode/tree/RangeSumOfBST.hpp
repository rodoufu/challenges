// https://leetcode.com/problems/range-sum-of-bst/
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
    TreeNode* minBST(TreeNode* root) {
        if (!root)
            return nullptr;
        if (!root->left)
            return root;
        return minBST(root->left);
    }
    TreeNode* maxBST(TreeNode* root) {
        if (!root)
            return nullptr;
        if (!root->right)
            return root;
        return maxBST(root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) {
            return 0;
        }
        //printf("%d\n", root->val);
        int resp = (root->val >= L && root->val <= R) ? root->val : 0;
        auto maxL = maxBST(root->left);
        if (maxL && maxL->val >= L) {
            resp += rangeSumBST(root->left, L, R);
        }
        auto minR = minBST(root->right);
        if (minR && minR->val <= R) {
            resp += rangeSumBST(root->right, L, R);
        }
        return resp;
    }
};
