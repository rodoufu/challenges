//https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        stack<int> values;
        auto it = head;
        while (it) {
            values.push(it->val);
            it = it->next;
        }
        it = head;
        while (it) {
            if (it->val != values.top()) {
                return false;
            }
            values.pop();
            it = it->next;
        }
        return true;
    }
};
