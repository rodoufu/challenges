// https://leetcode.com/problems/design-linked-list
type nodeInt struct {
    val int
    next *nodeInt
    toTheEnd int
}

type MyLinkedList struct {
    root *nodeInt
}


func Constructor() MyLinkedList {
    return MyLinkedList{}
}


func (this *MyLinkedList) Get(index int) int {
    if this.root == nil || this.root.toTheEnd <= index {
        // fmt.Println(this.String())
        return -1
    }
    current := this.root
    for i := 0; i < index; i++ {
        current = current.next
    }
    // fmt.Println(this.String())
    return current.val
}


func (this *MyLinkedList) AddAtHead(val int)  {
    this.AddAtIndex(0, val)
}


func (this *MyLinkedList) AddAtTail(val int)  {
    if this.root == nil {
        this.AddAtIndex(0, val)
    } else {
        this.AddAtIndex(this.root.toTheEnd, val)
    }
}


func (this *MyLinkedList) AddAtIndex(index int, val int)  {
    // fmt.Printf("AddAtIndex(%v, %v) ", index, val)
    if index == 0 {
        curr := 0
        if this.root != nil {
            curr = this.root.toTheEnd
        }
        head := nodeInt {
            val: val,
            next: this.root,
            toTheEnd: curr + 1,
        }
        this.root = &head
        // fmt.Println(this.String())
        return
    }

    if this.root == nil || this.root.toTheEnd < index {
        // fmt.Println(this.String())
        return
    }

    current := this.root
    for i := 0; i < index - 1; i++ {
        current.toTheEnd++
        current = current.next
    }
    current.toTheEnd++
    // fmt.Printf("current: %v ", *current)
    current.next = &nodeInt {
        val: val,
        next: current.next,
        toTheEnd: current.toTheEnd - 1,
    } 
    // fmt.Println(this.String())
}


func (this *MyLinkedList) DeleteAtIndex(index int)  {
    // fmt.Printf("DeleteAtIndex(%v)", index)
    if index == 0 {
        if this.root != nil {
            this.root = this.root.next
            // fmt.Println(this.String())
            return
        }
    }

    if this.root == nil || this.root.toTheEnd <= index {
        // fmt.Println(this.String())
        return
    }

    current := this.root
    for i := 0; i < index - 1; i++ {
        current.toTheEnd--
        current = current.next
    }
    current.toTheEnd--
    if current.next == nil {
        panic("it should not happen")
        // fmt.Println("it should not happen")
    } else {
        current.next = current.next.next
    }
    // fmt.Println(this.String())
}

func (this *MyLinkedList) String() string {
    var sb strings.Builder

    sb.WriteRune('[')

    for it := this.root; it != nil; it = it.next {
        sb.WriteString(fmt.Sprintf("(v: %v, te: %v), ", it.val, it.toTheEnd))
    }

    sb.WriteRune(']')

    return sb.String()
}


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
 
