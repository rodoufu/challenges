// https://leetcode.com/problems/binary-search-tree-iterator
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    queue<int> values;
    void update(TreeNode* root) {
        if (!root) {
            return;
        }
        update(root->left);
        values.push(root->val);
        update(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        update(root);
    }
    
    /** @return the next smallest number */
    int next() {
        auto v = values.front();
        values.pop();
        return v;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !values.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
