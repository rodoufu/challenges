// https://leetcode.com/problems/average-of-levels-in-binary-tree/

type avgCalc struct {
    total int
    count int
}

func (a *avgCalc) Avg() float64 {
    return float64(a.total) / float64(a.count)
}

func (a *avgCalc) Add(value int) {
    a.total += value
    a.count++
}

type nodeLevel struct {
    node *TreeNode
    level int
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func averageOfLevels(root *TreeNode) []float64 {
    if root == nil {
        return []float64{}
    }
    levelAvg := map[int]*avgCalc{}
    nodes := []nodeLevel{
        {
            node: root,
            level: 0,
        },
    }
    
    maxLevel := 0
    for len(nodes) > 0 {
        nodeIt := nodes[len(nodes) - 1]
        nodes = nodes[:len(nodes) - 1]
        
        if nodeIt.level > maxLevel {
            maxLevel = nodeIt.level
        }
        
        level, ok := levelAvg[nodeIt.level]
        if !ok {
            level = &avgCalc{}
        }
        level.Add(nodeIt.node.Val)
        
        if nodeIt.node.Left != nil {
            nodes = append(nodes, nodeLevel{
                node: nodeIt.node.Left,
                level: nodeIt.level + 1,
            })
        }
        if nodeIt.node.Right != nil {
            nodes = append(nodes, nodeLevel{
                node: nodeIt.node.Right,
                level: nodeIt.level + 1,
            })
        }
        
        levelAvg[nodeIt.level] = level
    }
    
    var resp []float64
    for i := 0; i <= maxLevel; i++ {
        resp = append(resp, levelAvg[i].Avg())
    }
    return resp
}
