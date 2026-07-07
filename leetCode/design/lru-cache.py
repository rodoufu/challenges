# https://leetcode.com/problems/lru-cache

class Node:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.previous = None 
        self.next = None 
    
    def print(self):
        if self.previous:
            print(f", ", end="")
        else:
            print(f"[", end="")

        print(f"{self.value}", end="")
        if self.next:
            self.next.print()
        else:
            print("]")
    
    def __str__(self):
        return f"{{k: {self.key}, v: {self.value}}}"

    def __repr__(self):
        return str(self)


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head: Node = None
        self.tail: Node = None
        self.key_node = {}
    
    def move_to_head(self, node: Node):
        if self.head == node or self.head == self.tail:
            return
        
        if node == self.tail:
            tail = self.tail
            previous = tail.previous
            if previous:
                previous.next = None
            self.tail = previous
        else:
            previous = node.previous
            node_next = node.next
            if previous:
                previous.next = node_next
            if node_next:
                node_next.previous = previous
        
        node.previous = None
        head = self.head
        node.next = head
        if head:
            head.previous = node
        self.head = node

    def get(self, key: int) -> int:
        # print("get ", end="")
        if key in self.key_node:
            node = self.key_node[key]
            self.move_to_head(node)

            # print(f"k: {key}, head: {self.head}, tail: {self.tail}")
            # print(f"key_node: {self.key_node}")
            # self.head.print()
            return node.value
        
        # print(f"not - k: {key}, head: {self.head}, tail: {self.tail}")
        # print(f"key_node: {self.key_node}")
        # self.head.print()
        return -1

    def put(self, key: int, value: int) -> None:
        # print("put ", end="")
        if key in self.key_node:
            node = self.key_node[key]
            node.value = value

            self.move_to_head(node)
        else:
            node = Node(key, value)
            node.next = self.head
            head = self.head
            self.head = node
            if head:
                head.previous = node
            if not self.tail:
                self.tail = node
            self.key_node[key] = node

        if len(self.key_node) > self.capacity:
            node = self.tail
            previous = node.previous
            if previous:
                previous.next = None
            self.tail = previous
            del self.key_node[node.key]
        # print(f"k: {key}, v: {value}, head: {self.head}, tail: {self.tail}")
        # print(f"key_node: {self.key_node}")
        # self.head.print()



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
