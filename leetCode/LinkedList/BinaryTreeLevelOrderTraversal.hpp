//https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resp;
        if (root) {
            resp.push_back(vector<int>());
            resp[0].push_back(root->val);
            
            vector<vector<int>> respLeft = root->left ? levelOrder(root->left) : vector<vector<int>>();
            vector<vector<int>> respRight = root->right ? levelOrder(root->right) : vector<vector<int>>();
            
            int sizeLeft = respLeft.size();
            int sizeRight = respRight.size();
            int size = max(sizeLeft, sizeRight);
            for (int i = 0; i < size; ++i) {
                vector<int> actual;
                actual.reserve((i < sizeLeft ? respLeft[i].size() : 0) + (i < sizeRight ? respRight[i].size() : 0));
                if (i < sizeLeft) {
                    actual.insert(actual.end(), respLeft[i].begin(), respLeft[i].end());
                }
                if (i < sizeRight) {
                    actual.insert(actual.end(), respRight[i].begin(), respRight[i].end());
                }
                
                resp.push_back(actual);
            }
        }
        return resp;
    }
};
