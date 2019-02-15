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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return nullptr;
        }
        
        auto node = new ListNode(0);
        auto head = node;
        ListNode *old = nullptr;
        while (l1 || l2) {
            node->next = new ListNode(0);
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    node->val = l1->val;
                    l1 = l1->next;
                } else {
                    node->val = l2->val;
                    l2 = l2->next;
                }
            } else if (l1) {
                node->val = l1->val;
                l1 = l1->next;
            } else {
                node->val = l2->val;
                l2 = l2->next;
            }
            old = node;
            node = node->next;
        }
        
        delete old->next;
        old->next = nullptr;
        return head;
    }
};
