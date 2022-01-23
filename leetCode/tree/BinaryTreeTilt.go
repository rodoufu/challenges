// https://leetcode.com/problems/binary-tree-tilt/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumTree(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return root.Val + sumTree(root.Left) + sumTree(root.Right)
}

func tilt(root *TreeNode) int {
    if root == nil {
        return 0
    }
    resp := sumTree(root.Left) - sumTree(root.Right)
    if resp < 0 {
        resp *= -1
    }
    //fmt.Printf("(%v)-%v\n", root.Val, resp)
    return resp
}

func findTilt(root *TreeNode) int {
    if root == nil {
        return 0
    }
    resp := tilt(root)
    if root.Left != nil {
        resp += findTilt(root.Left)
    }
    if root.Right != nil {
        resp += findTilt(root.Right)
    }
    
    return resp
}
