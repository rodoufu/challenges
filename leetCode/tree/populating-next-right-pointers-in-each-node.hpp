// https://leetcode.com/problems/populating-next-right-pointers-in-each-node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        queue<tuple<Node*, int>> fila;
        fila.push(make_tuple(root, 0));
        
        int lastIndex = -1;
        Node* lastNode = nullptr;

        while (!fila.empty()) {
            auto it = fila.front();
            fila.pop();

            auto node = get<0>(it);
            auto index = get<1>(it);
            //printf("v: %d, i: %d\n", node->val, index);
            if (index == lastIndex) {
                lastNode->next = node;
            }
            if (node->left) {
                fila.push(make_tuple(node->left, index + 1));
                fila.push(make_tuple(node->right, index + 1));
            }
            lastNode = node;
            lastIndex = index;
        }

        return root;
    }
};
