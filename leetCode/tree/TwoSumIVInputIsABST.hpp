// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> values;
        stack<TreeNode*> bag;
        if (root)
            bag.emplace(root);
        while (!bag.empty()) {
            auto it = bag.top();
            bag.pop();
            
            if (it->left)
                bag.emplace(it->left);
            if (it->right)
                bag.emplace(it->right);
            
            if (values.find(k - it->val) != values.end())
                return true;
            values.emplace(it->val);
        }
        return false;
    }
};
