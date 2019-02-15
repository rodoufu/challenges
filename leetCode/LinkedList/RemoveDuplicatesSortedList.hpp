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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto it = head, next = head->next;
        while (next) {
            if (it->val == next->val) {
                auto temp = it->next;
                it->next = next->next;
                next = it->next;
                delete temp;
            } else {
                it = next;
                next = it->next;
            }
        }
        return head;
    }
};
