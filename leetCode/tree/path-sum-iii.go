// https://leetcode.com/problems/path-sum-iii/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSumCounter(root *TreeNode, targetSum int, soFar []int, counter map[int]int) int {
    //fmt.Printf("r:%+v, targetSum:%v, soFar: %v, counter: %+v, l:%v\n", root.Val, targetSum, soFar, counter, len(soFar)+1)
    counter[root.Val]++
    soFarNew := make([]int, 0, len(soFar)+1)
    for _, v := range soFar {
        counter[v + root.Val]++
        soFarNew = append(soFarNew, v + root.Val)
    }
    soFarNew = append(soFarNew, root.Val)

    //fmt.Printf("r:%+v, targetSum:%v, soFar: %+v, counter: %+v\n", root.Val, targetSum, soFar, counter)
    if root.Left != nil {
        pathSumCounter(root.Left, targetSum, soFarNew, counter)
    }
    if root.Right != nil {
        pathSumCounter(root.Right, targetSum, soFarNew, counter)
    }
    return counter[targetSum]
}

func pathSum(root *TreeNode, targetSum int) int {
    if root == nil {
        return 0
    }
    return pathSumCounter(root, targetSum, []int{}, map[int]int{})
}
