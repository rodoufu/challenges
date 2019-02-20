//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* before = nullptr;
        auto node = head;
        auto it = head;

        for (int i = 1; i < n; ++i) {
            it = it->next;
        }
        while (it->next) {
            before = node;
            node = node->next;
            it = it->next;
        }
        
        if (before) {
            before->next = node->next;
        } else if (node == it) {
            head = nullptr;
        } else {
            head = node->next;
        }
        delete node;
                
        return head;
    }
};
