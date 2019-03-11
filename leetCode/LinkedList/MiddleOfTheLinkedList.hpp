//https://leetcode.com/problems/middle-of-the-linked-list
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
    ListNode* middleNode(ListNode* head) {
        auto first = head;
        auto second = head;
        while (second) {
            //printf("f:%d,s:%d\n", first->val, second->val);
            second = second->next;
            if (!second) {
                break;
            }
            first = first->next;
            second = second->next;
        }
        return first;
    }
};
