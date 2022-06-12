// https://leetcode.com/problems/partition-list/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func printList(head *ListNode, maxSize int) {
    if head == nil {
        fmt.Println("empty")
        return
    }
    
    fmt.Printf("%v", head.Val)
    head = head.Next
    
    for i := 0; i < maxSize && head != nil; i++ {
        fmt.Printf(" -> %v ", head.Val)
        head = head.Next
    }
    fmt.Println("")
}

func partition(head *ListNode, x int) *ListNode {
    if head == nil {
        return nil
    }
    var before, beforeTail, after, afterTail *ListNode
    
    for head != nil {
        //fmt.Printf("head: %v\n", head)
        if head.Val < x {
            if before == nil {
                before = head
                beforeTail = head
            } else {
                beforeTail.Next = head
                beforeTail = beforeTail.Next
            }
        } else {
            if after == nil {
                after = head
                afterTail = head
            } else {
                afterTail.Next = head
                afterTail = afterTail.Next
            }
        }
        head = head.Next
    }
    
    //fmt.Printf("head: %v, before: %v, beforeTail: %v, after:%v, afterTail: %v, node: %v\n", head, before, beforeTail, after, afterTail, node)
    //fmt.Printf("head: %v, before: %v, beforeTail: %v, after:%v, afterTail: %v\n", head, before, beforeTail, after, afterTail)
    
    if afterTail != nil {
       afterTail.Next = nil 
    }
    //beforeTail.Next = nil
    //afterTail.Next = nil
    //printList(before, 10)
    //printList(after, 10)
    
    
    if before == nil {
        return after
    }
    beforeTail.Next = after
    //node.Next = after
    
    //printList(before, 10)
    
    return before
}
