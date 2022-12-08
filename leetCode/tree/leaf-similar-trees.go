// https://leetcode.com/problems/leaf-similar-trees/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSequence(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    if root.Left == nil && root.Right == nil {
        return []int { root.Val }
    }
    var resp []int
    resp = append(resp, leafSequence(root.Left)...)
    resp = append(resp, leafSequence(root.Right)...)
    return resp
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    ls1 := leafSequence(root1)
    ls2 := leafSequence(root2)
    fmt.Printf("ls1: %v\n", ls1)
    fmt.Printf("ls2: %v\n", ls2)
    
    if len(ls1) != len(ls2) {
        return false
    }
    for i, x := range ls1 {
        if x != ls2[i] {
            return false
        }
    }
    return true
}
