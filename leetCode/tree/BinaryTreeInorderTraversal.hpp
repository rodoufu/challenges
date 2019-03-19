// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resp;
        if (!root) {
            return resp;
        }
        stack<tuple<TreeNode*, int> > nodes;
        nodes.push(make_tuple(root, 0));
        
        while (!nodes.empty()) {
            auto node_idx = nodes.top();
            auto node = get<0>(node_idx);
            auto idx = get<1>(node_idx);
            //printf("%d:%d-%d,%d ", node->val, idx, count, nodes.size());
            
            if (idx == 0 && node->left) {
                //printf(" .1\n");
                nodes.pop();
                nodes.push(make_tuple(node, 1));
                nodes.push(make_tuple(node->left, 0));
            } else {
                //printf(" .2\n");
                nodes.pop();
                resp.push_back(node->val);
                if (node->right) {
                    nodes.push(make_tuple(node->right, 0));
                }
            }
        }
        
        return resp;
    }
};
