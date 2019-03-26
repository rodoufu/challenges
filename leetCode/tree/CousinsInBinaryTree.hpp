// https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) {
            return false;
        }
        stack<tuple<TreeNode*, int, TreeNode*> > pilha;
        pilha.push(make_tuple(root, 0, nullptr));
        bool gx = false, gy = false;
        tuple<TreeNode*, int, TreeNode*> vx, vy;
        
        while (!pilha.empty() && (!gx || !gy)) {
            auto node_level_father = pilha.top();
            pilha.pop();
            
            auto& node = get<0>(node_level_father);
            auto& level = get<1>(node_level_father);
            auto& father = get<2>(node_level_father);
            if (node->val == x) {
                vx = make_tuple(node, level, father);
                gx = true;
            }
            if (node->val == y) {
                vy = make_tuple(node, level, father);
                gy = true;
            }
            
            if (node->left) {
                pilha.push(make_tuple(node->left, level + 1, node));
            }
            if (node->right) {
                pilha.push(make_tuple(node->right, level + 1, node));
            }
        }
        
        if (!gx || !gy || get<1>(vx) != get<1>(vy) || get<2>(vx) == get<2>(vy)) {
            return false;
        }
        
        return true;
    }
};
