// https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
private:
    unordered_map<Node *, Node *> nodes;

    Node* copyRandomList2(Node* head) {
        if (!head) {
            return nullptr;
        }
        if (nodes.find(head) != nodes.end()) {
            return nodes[head];
        }
        auto resp = new Node(head->val, nullptr, nullptr);
        nodes.emplace(head, resp);
        resp->next = copyRandomList2(head->next);
        resp->random = copyRandomList2(head->random);
        
        return resp;
    }
public:
    Node* copyRandomList(Node* head) {
        nodes.clear();
        return copyRandomList2(head);
    }
};
