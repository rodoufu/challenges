// https://leetcode.com/problems/increasing-order-search-tree/
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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* resp = nullptr;
        TreeNode* temp = nullptr;

        auto addNode = [&temp, &resp](TreeNode* it) {
            if (!temp) {
                resp = temp = new TreeNode(it->val);
            } else {
                temp->right = new TreeNode(it->val);
                temp = temp->right;
            }
            //delete it;
        };

        stack<TreeNode *> pilha;
        auto addToPilha = [&pilha](TreeNode* it) {
            while (it) {
                pilha.push(it);
                it = it->left;
            }
        };

        addToPilha(root);
        while (!pilha.empty()) {
            auto node = pilha.top();
            pilha.pop();
            //printf("%d\n", node->val);
            addNode(node);
            if (node->right) {
                addToPilha(node->right);
            }
        }
        
        return resp;
    }
};
