# https://leetcode.com/problems/construct-string-from-binary-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t:
            return ""
        left = "" if not t.left else self.tree2str(t.left)
        right = "" if not t.right else self.tree2str(t.right)
        if len(left) > 0 and len(right) > 0:
            return f"{t.val}({left})({right})"
        if len(left) > 0:
            return f"{t.val}({left})"
        if len(right) > 0:
            return f"{t.val}({left})({right})"
        else:
            return f"{t.val}"
        
