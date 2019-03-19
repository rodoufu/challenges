// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }
        stack<tuple<TreeNode*, int> > nodes;
        nodes.push(make_tuple(root, 0));
        
        int count = 0;
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
                ++count;
                if (count == k) {
                    return node->val;
                }
                if (node->right) {
                    nodes.push(make_tuple(node->right, 0));
                }
            }
        }
        
        return 0;
    }
};
