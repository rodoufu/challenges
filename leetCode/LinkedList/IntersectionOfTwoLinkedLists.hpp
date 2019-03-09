//https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0, sizeB = 0;
        auto tempA = headA;
        while (tempA) {
            ++sizeA;
            tempA = tempA->next;
        }
        auto tempB = headB;
        while (tempB) {
            ++sizeB;
            tempB = tempB->next;
        }
        int minV = min(sizeA, sizeB);
        sizeA -= minV;
        sizeB -= minV;
        
        tempA = headA;
        tempB = headB;
        for (int i = 0; i < sizeA; ++i) {
            tempA = tempA->next;
        }
        for (int i = 0; i < sizeB; ++i) {
            tempB = tempB->next;
        }
        
        ListNode * resp = nullptr;
        while (tempA) {
            if (resp) {
                if (tempA != tempB) {
                    resp = nullptr;
                }
            } else if (tempA == tempB) {
                resp = tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return resp;
    }
};
