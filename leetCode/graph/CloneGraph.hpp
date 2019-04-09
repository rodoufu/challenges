// https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<int, Node*> values;

    Node* cloneGraph2(Node* node) {
        if (!node) {
            return nullptr;
        }
        if (values.find(node->val) != values.end()) {
            return values[node->val];
        }
        //printf("n:%d,s:%d\n", node->val, values.size());

        auto resp = new Node(node->val, vector<Node*>());
        values.emplace(node->val, resp);
        for (auto &x : node->neighbors) {
            //printf("x:%d\n", x->val);
            resp->neighbors.push_back(cloneGraph2(x));
        }
        return resp;
    }
public:
    Node* cloneGraph(Node* node) {
        values.clear();
        return cloneGraph2(node);
    }
};
