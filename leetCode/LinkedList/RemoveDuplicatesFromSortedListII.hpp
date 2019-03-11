//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* deleteDuplicates(ListNode* head, int* val) {
        //printf("(%d,%d)\n", head->val, val ? *val : 0);
        if (val) {
            if (head->val == *val) {
                if (head->next) {
                    auto resp = deleteDuplicates(head->next, val);
                    delete head;
                    return resp;
                } else {
                    delete head;
                    return nullptr;
                }
            } else {
                /*
                if (head->next) {
                    head->next = deleteDuplicates(head->next, nullptr);
                }
                return head;
                */
                return deleteDuplicates(head, nullptr);
            }
        } else {
            if (head->next) {
                if (head->val == head->next->val) {
                    return deleteDuplicates(head, &head->val);
                } else {
                    head->next = deleteDuplicates(head->next, nullptr);
                    return head;
                }
            } else {
                return head;
            }
        }
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        return deleteDuplicates(head, nullptr);
    }
};
