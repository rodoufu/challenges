// https://leetcode.com/problems/reverse-nodes-in-k-group/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func printNodes(head *ListNode) {
    if head != nil {
        fmt.Printf("%v", head.Val)
        head = head.Next
    }
    for head != nil {
        fmt.Printf(" -> %v", head.Val)
        head = head.Next
    }
    fmt.Println("")
}

func findNodeK(head *ListNode, k int) *ListNode {
    for i := 1; i < k - 1 && head != nil; i++ {
        head = head.Next
    }
    return head
}

func printNode(head *ListNode) {
    fmt.Printf("%v\n", head.Val)
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if k <= 1 {
		return head
	}
	toReverse := make([]*ListNode, 0, k)
	current := head
	for i := 0; i < k; i++ {
		toReverse = append(toReverse, current)
		current = current.Next
		if current == nil && i < k-1 {
			return head
		}
	}
	var nextHead *ListNode
	if current != nil {
		nextHead = reverseKGroup(current, k)
	}
	newHead := toReverse[k-1]
	it := newHead
	for i := k - 2; i >= 0; i-- {
		it.Next = toReverse[i]
		it = it.Next
	}
	it.Next = nextHead

	return newHead
}
