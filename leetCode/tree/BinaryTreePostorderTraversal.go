// https://leetcode.com/problems/binary-tree-postorder-traversal/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    var resp []int
    if root.Left != nil {
        resp = append(resp, postorderTraversal(root.Left)...)
    }
    if root.Right != nil {
        resp = append(resp, postorderTraversal(root.Right)...)
    }
    resp = append(resp, root.Val)
    return resp
}
