// https://leetcode.com/problems/linked-list-random-node/
import "math/rand"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type Solution struct {
    vals []int
}


func Constructor(head *ListNode) Solution {
    s := Solution{}

    for head != nil {
        s.vals = append(s.vals, head.Val)
        head = head.Next
    }

    return s
}


func (this *Solution) GetRandom() int {
    r := rand.Int31n(int32(len(this.vals)))
    return this.vals[r]
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(head);
 * param_1 := obj.GetRandom();
 */
 
