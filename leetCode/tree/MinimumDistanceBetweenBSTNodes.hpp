// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    int minDiffInBST(TreeNode* root) {
        set<int> vals;
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
            vals.emplace(it->val);
        }
        
        int minv = *min_element(vals.begin(), vals.end());
        int maxv = *max_element(vals.begin(), vals.end());
        int diff = maxv - minv;
        int lastv = maxv + diff + 1;
        for (auto &x : vals) {
            if (abs(x - lastv) < diff) {
                diff = abs(x - lastv);
            }
            lastv = x;
        }
        return diff;
    }
};
