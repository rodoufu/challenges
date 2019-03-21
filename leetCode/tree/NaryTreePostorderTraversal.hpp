// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private:
    void postorder(Node * root, vector<int> & resp) {
        for (auto &x : root->children) {
            postorder(x, resp);
        }
        resp.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        if (!root) {
            return vector<int>();
        }
        vector<int> resp;
        postorder(root, resp);
        
        return resp;
    }
};
