# https://leetcode.com/problems/remove-nth-node-from-end-of-list/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return None
        nodes = []
        it = head
        while it:
            nodes.append(it)
            it = it.next
        if len(nodes) == 1:
            return None
        
        previous = None
        for i in range(n - 1):
            previous = nodes.pop()
        nodes.pop()
        if nodes:
            nodes[-1].next = previous
        else:
            return previous

        return head
        
