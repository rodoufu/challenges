// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
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
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int depth = 0;
        for (auto &x : root->children) {
            depth = max(depth, maxDepth(x));
        }
        
        return depth + 1;
    }
};
