// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
/*
func nodeString(root *TreeNode) string {
    if root == nil {
        return "nil"
    }
    return fmt.Sprintf("{Val: %v, Left: %v, Right: %v}", root.Val, nodeString(root.Left), nodeString(root.Right))
}
*/

func findSecondMinimumValueCurrent(root *TreeNode, second int) int {
    //fmt.Println(nodeString(root))
    if root == nil || root.Left == nil {
        return second
    }
    if root.Val == root.Left.Val && root.Val == root.Right.Val {
        values := []int{
            //second,
            findSecondMinimumValueCurrent(root.Left, second),
            findSecondMinimumValueCurrent(root.Right, second),
        }
        /*if values[2] < values[1] {
            values[2], values[1] = values[1], values[2]
        }*/
        if values[1] < values[0] {
            values[1], values[0] = values[0], values[1]
        }
        /*if values[2] < values[1] {
            values[2], values[1] = values[1], values[2]
        }*/
        return values[0]
    }
    if root.Val == root.Left.Val {
        return findSecondMinimumValueCurrent(root.Left, root.Right.Val)
    }
    return findSecondMinimumValueCurrent(root.Right, root.Left.Val) 
}

func findSorting(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    if root.Left == nil {
        return []int{ root.Val }
    }
    values := make(map[int]struct{})
    for _, num := range findSorting(root.Left) {
        values[num] = struct{}{}
    }
    for _, num := range findSorting(root.Right) {
        values[num] = struct{}{}
    }
    var resp []int
    for key, _ := range values {
        resp = append(resp, key)
    }
    switch len(resp) {
    case 0:
        return nil
    case 1:
        return resp
    default:
        sort.Ints(resp)
        return resp[:2]
    }
}

func findSecondMinimumValue(root *TreeNode) int {
    found := findSorting(root)
    if len(found) < 2 {
        return -1
    }
    return found[1]
}
