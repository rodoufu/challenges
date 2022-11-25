// https://leetcode.com/problems/diameter-of-binary-tree/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func height(root *TreeNode, nodeHeight map[*TreeNode]int) int {
    if root == nil {
        return 0
    }
    if h, ok := nodeHeight[root]; ok {
        return h
    }
    hL := height(root.Left, nodeHeight)
    hR := height(root.Right, nodeHeight)
    if hL > hR {
        nodeHeight[root] = 1 + hL
        return 1 + hL
    }
    nodeHeight[root] = 1 + hR
    return 1 + hR
}

func diameterOfBinaryTreeCache(root *TreeNode, nodeHeight map[*TreeNode]int) int {
    if root == nil {
        return 0
    }
    
    d := height(root.Left, nodeHeight) + height(root.Right, nodeHeight)
    dL := diameterOfBinaryTreeCache(root.Left, nodeHeight)
    dR := diameterOfBinaryTreeCache(root.Right, nodeHeight)
    
    //fmt.Printf("diameterOfBinaryTreeCache root: %v, nodeHeight: %v", root.Val, nodeHeight)
    //fmt.Printf(" d: %v, dL: %v, dR: %v\n", d, dL, dR)
    
    if d >= dL && d >= dR {
        return d
    }
    if dL >= d && dL >= dR {
        return dL
    }
    return dR
}

func diameterOfBinaryTree(root *TreeNode) int {
    return diameterOfBinaryTreeCache(root, make(map[*TreeNode]int))
}
