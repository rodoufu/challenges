# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        p_fathers = []
        q_fathers = []
        it = root
        while it and it != p:
            p_fathers.append(it)
            if it.val > p.val:
                it = it.left
            else:
                it = it.right
        if it and it.val == p.val:
            p_fathers.append(it)
        
        it = root
        while it and it != q:
            q_fathers.append(it)
            if it.val > q.val:
                it = it.left
            else:
                it = it.right
        if it and it.val == q.val:
            q_fathers.append(it)
        
        # print(f"p: {p}, q: {q}")
        # print(f"p_fathers: {p_fathers}")
        # print(f"q_fathers: {q_fathers}")
        
        i = 0
        len_p = len(p_fathers)
        len_q = len(q_fathers)
        while i < min(len_p, len_q):
            if p_fathers[i] == q_fathers[i]:
                i += 1
            else:
                break
        
        return p_fathers[i - 1]
