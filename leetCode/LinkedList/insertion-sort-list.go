// https://leetcode.com/problems/insertion-sort-list/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func insertionSortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    for it := head; it != nil; it = it.Next {
        smaller := it
        for jt := it.Next; jt != nil; jt = jt.Next {
            if jt.Val < smaller.Val {
                smaller = jt
            }
        }
        
        it.Val, smaller.Val = smaller.Val, it.Val
    }
    
    return head
}
