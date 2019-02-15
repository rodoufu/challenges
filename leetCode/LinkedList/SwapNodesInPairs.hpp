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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto repetir = head->next->next;
        auto antes = head;
        auto depois = head->next;
        swap(head, head->next);
        head->next = antes;
        head->next->next = repetir;
        if (repetir) {
            head->next->next = swapPairs(repetir);
        }
        return head;
    }
};
