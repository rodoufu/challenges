// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNodeQueue struct {
	node  *TreeNode
	level int
	next  *TreeNodeQueue
	last  *TreeNodeQueue
}

func (q *TreeNodeQueue) Add(node *TreeNode, level int) {
	if node == nil {
		return
	}
	if q.node == nil {
		q.node = node
		q.level = level
		q.next = nil
		q.last = nil
		return
	}

	last := &TreeNodeQueue{
		node:  node,
		level: level,
	}
	if q.next == nil {
		q.next = last
	}
	if q.last != nil {
		q.last.next = last
	}

	q.last = last
}

func (q *TreeNodeQueue) IsEmpty() bool {
	return q == nil || q.node == nil
}

func (q *TreeNodeQueue) Pop() (*TreeNode, int) {
	if q.IsEmpty() {
		return nil, 0
	}
	resp, level := q.node, q.level

	if q.next != nil {
		q.node = q.next.node
		q.level = q.next.level
		q.next.last = q.last
		q.next = q.next.next
	} else {
		q.node = nil
	}

	return resp, level
}

func (q *TreeNodeQueue) String() string {
	if q == nil || q.node == nil {
		return "{}"
	}
	var sb strings.Builder
	sb.WriteString("{")
	current := q
	for current != nil {
		if current != q {
			sb.WriteString(", ")
		}
		sb.WriteString(fmt.Sprintf("(%v,%v)", current.node.Val, current.level))
		current = current.next
	}
	sb.WriteString("}")
	return sb.String()
}

func reverseOddLevels(root *TreeNode) *TreeNode {
	if root == nil || (root.Left == nil && root.Right == nil) {
		return root
	}
	var nodeVals [][]int
	fifo := &TreeNodeQueue{}
	fifo.Add(root, 0)
	//fmt.Printf("fifo: %v\n", fifo)
	for !fifo.IsEmpty() {
		node, level := fifo.Pop()
		//fmt.Printf("node: %v, level: %v, fifo: %v - begin\n", node, level, fifo)
		nodeVals = append(nodeVals, []int{node.Val, level})
		if node.Left != nil {
			fifo.Add(node.Left, level+1)
		}
		if node.Left != nil {
			fifo.Add(node.Right, level+1)
		}

		//fmt.Printf("node: %v, level: %v, fifo: %v - end\n", node, level, fifo)
	}
	//fmt.Printf("nodeVals: %v\n", nodeVals)

	lenV := len(nodeVals)
	for i := 0; i < lenV; i++ {
		if nodeVals[i][1]%2 == 1 {
			end := i
			for ; end < lenV && nodeVals[end][1]%2 == 1; end++ {
			}
			end--
			for j := 0; j <= (end-i)/2; j++ {
				nodeVals[i+j], nodeVals[end-j] = nodeVals[end-j], nodeVals[i+j]
			}
			i = end
		}
	}

	//fmt.Printf("nodeVals: %v\n", nodeVals)
    fifo.Add(root, 0)
    var nodes []*TreeNode
    for !fifo.IsEmpty() {
		node, _ := fifo.Pop()
        //fmt.Printf("node: %v, level: %v, fifo: %v - begin\n", node, idx, fifo)
        nodes = append(nodes, node)
        
        if node.Left != nil {
            //idx++
			fifo.Add(node.Left, 0)
		}
		if node.Left != nil {
            //idx++
			fifo.Add(node.Right, 0)
		}
        //fmt.Printf("node: %v, level: %v, fifo: %v - end\n", node, idx, fifo)
    }
    
    for i, vals := range nodeVals {
        nodes[i].Val = vals[0]
    }
    

	return root
}

