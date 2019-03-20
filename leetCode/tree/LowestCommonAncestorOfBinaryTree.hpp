// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define PRINT_NdVal(X) \
    for (auto &_XX_ : (X)) { \
        printf("%d ", _XX_->val); \
    } \
    putchar('\n')
#define PRINT_NdValS(Y, X) puts(Y); PRINT_NdVal(X)

class Solution {
private:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* p) {
        unordered_map<TreeNode*, TreeNode*> pre;
        stack<TreeNode*> pilha;
        pilha.push(root);
        pre.emplace(root, nullptr);
        while (!pilha.empty()) {
            //auto node_path = pilha.top();
            auto node = pilha.top();
            pilha.pop();

            //auto node = get<0>(node_path);
            //auto &path = get<1>(node_path);
            //path.push_back(node);            
            //printf("%d\n", node->val);

            if (node == p) {
                vector<TreeNode*> resp;
                while (node) {
                    resp.push_back(node);
                    node = pre[node];
                }
                return vector<TreeNode*>(resp.rbegin(), resp.rend());
            }

            if (node->left) {
                pilha.push(node->left);
                pre.emplace(node->left, node);
            }
            if (node->right) {
                pilha.push(node->right);
                pre.emplace(node->right, node);
            }
        }
        
        return vector<TreeNode*>();
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return root;
        }
        
        vector<TreeNode*> pp(getPath(root, p));
        //PRINT_NdValS("pp", pp);      
        
        bool pe = pp.empty();
        bool qe = false;
        unordered_set<TreeNode*> both;
        {
            vector<TreeNode*> qp(getPath(root, q));
            bool qe = qp.empty();
            //PRINT_NdValS("qp", qp);

            unordered_set<TreeNode*> ps(pp.begin(), pp.end());
            unordered_set<TreeNode*> qs(qp.begin(), qp.end());

            for (auto &x : pp) {
                if (qs.find(x) != qs.end()) {
                    both.emplace(x);
                }
            }
        }
        //PRINT_NdValS("both", both);
        
        for (auto it = pp.rbegin(); it != pp.rend(); ++it) {
            if (both.find(*it) != both.end()) {
                return *it;
            }
        }
        
        if (pe && !qe) {
            return q;
        }
        if (qe && !pe) {
            return p;
        }
        
        return nullptr;
    }
};
