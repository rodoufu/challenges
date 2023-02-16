// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */

func flatten_node(root *Node, next *Node) (*Node, *Node) {
    //fmt.Printf("r: %+v, n: %+v\n", root, next)
    if root == nil {
        return next, nil
    }
    rNext := root.Next
    var last *Node
    if root.Child != nil {
        root.Next, last = flatten_node(root.Child, rNext)
        root.Child = nil
        if root.Next != nil {
            root.Next.Prev = root
        }
    }
    if rNext != nil {
        _, last = flatten_node(rNext, nil)
    }
    if last == nil && root.Next == nil {
        last = root
    }

    //fmt.Printf("r: %+v, n: %+v, l: %+v\n", root, next, last)
    if last != nil {
        last.Next = next
        if next != nil {
            next.Prev = last
        }
    }

    return root, last
}

func printNode(root *Node) {
    fmt.Printf("{\n")
    for root != nil {
        //fmt.Printf("\t%v: %+v, \n", &root, root)
        fmt.Printf("\t{Val: %v, ", root.Val)
        if root.Prev != nil {
            fmt.Printf("Prev: %v, ", root.Prev.Val)
        } else {
            fmt.Printf("Prev: %v, ", root.Prev)
        }
        if root.Next != nil {
            fmt.Printf("Next: %v, ", root.Next.Val)
        } else {
            fmt.Printf("Next: %v, ", root.Next)
        }
        if root.Child != nil {
            fmt.Printf("Child: %v}\n", root.Child.Val)
        } else {
            fmt.Printf("Child: %v}\n", root.Child)
        }

        root = root.Next
    }
    fmt.Printf("{\n")
}

func flatten(root *Node) *Node {
    head, _ := flatten_node(root, nil)

    //printNode(root)
    return head
}
