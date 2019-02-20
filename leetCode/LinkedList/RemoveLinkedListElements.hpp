//https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        /*
        if (!head->next && head->val == val) {
            delete head;
            return nullptr;
        }
        */
        auto it = head;
        while (it) {
            //printf("%d", it->val);
            if (it->val == val && it->next) {
                //printf("d");
                auto temp = it->next;
                it->val = temp->val;
                it->next = temp->next;
                delete temp;
            } else {
                //printf("n");
                it = it->next;
            }
            //printf("->");
        }
        it = head;
        while (it && it->next && it->next->next) {
            it = it->next;
        }
        if (it->next && it->next->val == val) {
            delete it->next;
            it->next = nullptr;
        }
        //printf("\n");
        if (!head->next && head->val == val) {
            delete head;
            return nullptr;
        }
        return head;
    }
};
