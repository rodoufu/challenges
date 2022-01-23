// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type visit struct {
    node *TreeNode
    visited bool
}

func getMinimumDifference(root *TreeNode) int {
    if root == nil {
        return -1
    }
    var pilha []*visit
    top := 0
    size := 0
    add := func(value *TreeNode, visited bool) {
        if value == nil {
            return
        }
        if top == size {
            pilha = append(pilha, &visit{
                node: value,
                visited: visited,
            })
            top++
            size++
        } else {
            pilha[top] = &visit{
                node: value,
                visited: visited,
            }
            top++
        }
    }
    pop := func() (*TreeNode, bool) {
        if top == 0 {
            return nil, false
        }
        top--
        return pilha[top].node, pilha[top].visited
    }
    add(root, false)
    var numbers []int
    
    for it, visited := pop(); it != nil; it, visited = pop() {
        if visited {
            numbers = append(numbers, it.Val)
        } else {
            add(it.Left, false)
            add(it, true)
            add(it.Right, false)
        }
    }
    lenN := len(numbers)
    minDif := numbers[0] - numbers[1]
    for i := 0; i < lenN; i++ {
        for j := i + 1; j < lenN; j++ {
            absDif := numbers[i] - numbers[j]
            if absDif < 0 {
                absDif *= -1
            }
            if absDif < minDif {
                minDif = absDif
            }
        }
    }
    
    return minDif
}
