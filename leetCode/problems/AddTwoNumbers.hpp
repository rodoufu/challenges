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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head = new ListNode(0);
        ListNode * it = nullptr;
        while (l1 || l2) {
            it = it ? it->next : head;
            if (l1) {
                it->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                it->val += l2->val;
                l2 = l2->next;
            }
            it->next = new ListNode(it->val > 9 ? 1 : 0);
            it->val %= 10;
        }
        if (!it->next->val) {
            delete it->next;
            it->next = nullptr;
        }
        
        return head;
    }
};
