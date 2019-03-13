// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        unordered_set<TreeNode*> pv;
        auto temp = root;
        //printf("p:%d,q:%d\n", p->val, q->val);
        while (temp) {
            //printf("%d ", temp->val);
            pv.emplace(temp);
            if (temp == p) break;
            if (temp->val > p->val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        //puts("-");
        
        temp = root;
        auto resp = root;
        while (temp) {
            //printf("%d ", temp->val);
            if (pv.find(temp) != pv.end()) {
                resp = temp;
            }
            if (temp == q) break;
            if (temp->val > q->val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        //puts("-");
        
        return resp;
    }
};
