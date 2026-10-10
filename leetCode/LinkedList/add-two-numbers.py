# https://leetcode.com/problems/add-two-numbers/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        resp = ListNode(0)
        it = resp
        while l1 and l2:
            it.next = ListNode(0)
            it = it.next
            it.val = carry + l1.val + l2.val
            carry = it.val // 10
            it.val %= 10
            l1 = l1.next
            l2 = l2.next

        while l1:
            it.next = ListNode(0)
            it = it.next
            it.val = carry + l1.val
            carry = it.val // 10
            it.val %= 10
            l1 = l1.next

        while l2:
            it.next = ListNode(0)
            it = it.next
            it.val = carry + l2.val
            carry = it.val // 10
            it.val %= 10
            l2 = l2.next

        if carry > 0:
            it.next = ListNode(carry)

        return resp.next
