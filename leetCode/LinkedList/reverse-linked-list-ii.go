// https://leetcode.com/problems/reverse-linked-list-ii/

func printToStr(head *ListNode, max int) {
    fmt.Printf("[")
    comma := false
    for i := 0; i != max && head != nil; i++ {
        if comma {
            fmt.Printf(", ")
        }
        fmt.Printf("%v", head.Val)
        comma = true
        head = head.Next
    }
    fmt.Printf("]\n")
}

func nodeToStr(node *ListNode) string {
    if node == nil {
        return "nil"
    }
    var sb strings.Builder
    sb.WriteString("{")
    sb.WriteString(fmt.Sprintf("Val:%v,Next:%v", node.Val, node.Next))
    sb.WriteString("")
    return sb.String()
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
    if left == right {
        return head
    }
    // printToStr(head, 100)
    
    current := head
    pos := 1
    var leftNode *ListNode
    var nodes []*ListNode
    
    for current != nil {
        // fmt.Printf("current: %+v, nodes: %v\n", current, nodes)
        if pos < left {
            leftNode = current
        }
        if pos >= left && pos <= right {
            nodes = append(nodes, current)
            if pos == right {
                break
            }
        }
        pos++
        current = current.Next
    }
    
    // fmt.Printf("\ncurrent: %+v, leftNode: %+v\n\n", nodeToStr(current), nodeToStr(leftNode))
    
    temp := current.Next
    if leftNode == nil {
        leftNode = &ListNode{}
    }
    currentR := leftNode
    lenNodes := len(nodes)
    for i := lenNodes - 1; i >= 0; i-- {
        node := nodes[i]
        // fmt.Printf("currentR: %+v, node: %+v\n", currentR, node)
        currentR.Next = node
        currentR = currentR.Next
    }
    currentR.Next = temp
    // fmt.Printf("\ncurrent: %+v, currentR: %+v, temp: %v\n", nodeToStr(current), nodeToStr(currentR), nodeToStr(temp))
    // fmt.Printf("leftNode: %v, leftNode.Next: %v\n\n", nodeToStr(leftNode), nodeToStr(leftNode.Next))
    
    if left == 1 {
        head = leftNode.Next
    }
    // printToStr(head, 100)
    return head
}
