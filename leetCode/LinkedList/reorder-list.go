// https://leetcode.com/problems/reorder-list/
func printList(nodes[]*ListNode) {
    fmt.Printf("{")
    for i, node := range nodes {
        if i > 0 {
            fmt.Printf(", ")
        }
        fmt.Printf("{Val: %v, Next:%v}", node.Val, node.Next)
    }
    fmt.Printf("}\n")
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {
    if head == nil {
        return
    }
    var nodes[]*ListNode
    for head != nil {
        nodes = append(nodes, head)
        head = head.Next
    }
    lenN := len(nodes)
    //printList(nodes)
    for i := 0; i < lenN/2; i++ {
        nodes[i].Next = nodes[lenN - i - 1]
        nodes[lenN - i - 1].Next = nodes[i + 1]
    }
    nodes[lenN/2].Next = nil
    //printList(nodes)
}
