# https://leetcode.com/problems/clone-graph/
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def __init__(self):
        self.already_cloned = {}

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        if node.val in self.already_cloned:
            return self.already_cloned[node.val]
        
        resp = Node(node.val, [])
        self.already_cloned[node.val] = resp
        for neighbor in node.neighbors:
            resp.neighbors.append(self.cloneGraph(neighbor))

        return resp
