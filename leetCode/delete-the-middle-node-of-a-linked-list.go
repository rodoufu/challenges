// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteMiddle(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return nil
    }
    initial := head
    end := head
    previous := head
    //fmt.Printf("i:%+v, e:%v before\n", initial, end)
    for end != nil && end.Next != nil {
        previous = initial
        initial = initial.Next
        end = end.Next
        if end != nil {
            end = end.Next
        }
        //fmt.Printf("i:%+v, e:%v, p: %v\n", initial, end, previous)
    }
    previous.Next = initial.Next
    //fmt.Printf("i:%+v, e:%v, p: %v after\n", initial, end, previous)
    return head
}
