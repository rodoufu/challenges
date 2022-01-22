// https://leetcode.com/problems/binary-tree-preorder-traversal/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    resp := []int{ root.Val }
    if root.Left != nil {
        resp = append(resp, preorderTraversal(root.Left)...)
    }
    if root.Right != nil {
        resp = append(resp, preorderTraversal(root.Right)...)
    }
    return resp
}
