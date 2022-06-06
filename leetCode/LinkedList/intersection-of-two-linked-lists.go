// https://leetcode.com/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    nodesMap := map[*ListNode]struct{}{}
    
    for headA != nil && headB != nil {
        if _, ok := nodesMap[headA]; ok {
            return headA
        }
        nodesMap[headA] = struct{}{}
        
        if _, ok := nodesMap[headB]; ok {
            return headB
        }
        nodesMap[headB] = struct{}{}
        
        headA = headA.Next
        headB = headB.Next
    }
    
    for headA != nil {
        if _, ok := nodesMap[headA]; ok {
            return headA
        }
        nodesMap[headA] = struct{}{}
        
        headA = headA.Next
    }
    
    for headB != nil {
        if _, ok := nodesMap[headB]; ok {
            return headB
        }
        nodesMap[headB] = struct{}{}
        
        headB = headB.Next
    }
    
    return nil
}
