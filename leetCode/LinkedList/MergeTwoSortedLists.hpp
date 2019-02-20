//https://leetcode.com/problems/merge-two-sorted-lists/
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
            return NULL;
        }
        ListNode * resp = new ListNode(0);
        ListNode * it = resp;
        while (l1 && l2) {
            it->next = new ListNode(0);
            if (l1->val < l2->val) {
                it->val = l1->val;
                l1 = l1->next;
            } else {
                it->val = l2->val;
                l2 = l2->next;
            }
            it = (l1 || l2) ? it->next : it;
        }
        while (l1) {
            it->next = new ListNode(0);
            it->val = l1->val;
            l1 = l1->next;
            it = (l1 || l2) ? it->next : it;
        }
        while (l2) {
            it->next = new ListNode(0);
            it->val = l2->val;
            l2 = l2->next;
            it = (l1 || l2) ? it->next : it;
        }
        delete it->next;
        it->next = NULL;
        return resp;
    }
};
