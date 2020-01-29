// https://leetcode.com/problems/subtree-of-another-tree
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
    bool equals(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t || s->val != t->val) {
            return false;
        }
        return equals(s->left, t->left) && equals(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> p;
        p.push(s);

        while (!p.empty()) {
            s = p.front();
            p.pop();

            if (equals(t, s)) {
                return true;
            }
            if (s->left) {
                p.push(s->left);
            }
            if (s->right) {
                p.push(s->right);
            }
        }
        return false;
    }
};
