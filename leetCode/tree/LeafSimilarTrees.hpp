// https://leetcode.com/problems/leaf-similar-trees/
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
    vector<int> getLeaves(TreeNode* root1) {
        stack<TreeNode *> pilha;
        pilha.push(root1);
        vector<int> values1;
        while (!pilha.empty()) {
            auto node = pilha.top();
            pilha.pop();
            
            if (!node->left && !node->right) {
                values1.push_back(node->val);
            } else {
                if (node->left) {
                    pilha.push(node->left);
                } 
                if (node->right) {
                    pilha.push(node->right);
                }
            }
        }
        
        return values1;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1) {
            return false;
        }
        if (!root2) {
            return false;
        }

        vector<int> values1(getLeaves(root1));
        vector<int> values2(getLeaves(root2));
        
        if (values1.size() != values2.size()) {
            return false;
        }
        
        for (auto it1 = values1.begin(), it2 = values2.begin(); it1 != values1.end(); ++it1, ++it2) {
            if (*it1 != *it2) {
                return false;
            }
        }
        
        return true;
    }
};
