# https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
	def serialize(self, root):
		"""Encodes a tree to a single string.

		:type root: TreeNode
		:rtype: str
		"""
		if not root or root.val is None:
			return ""
		return f"({root.val}:{self.serialize(root.left)},{self.serialize(root.right)})"

	def deserialize(self, data):
		"""Decodes your encoded data to tree.

		:type data: str
		:rtype: TreeNode
		"""
		if not data or len(data) == 0:
			return None
		data = data.strip()
		if data == "()":
			return None
		index = 0
		len_data = len(data)
		tree_stack = [TreeNode(None)]
		last_tree = None
		value = []

		while index < len_data:
			current = data[index]
			index += 1
			if current == '(':
				pass
			# tree_stack.append(TreeNode(None))
			elif current == ')':
				last_tree = tree_stack.pop()
				if last_tree.val is None:
					last_tree = tree_stack.pop()
				if last_tree.left and last_tree.left.val is None:
					last_tree.left = None
				if last_tree.right and last_tree.right.val is None:
					last_tree.right = None
			elif current == ':':
				last_tree = tree_stack.pop()
				last_tree.val = int(''.join(value))
				value.clear()

				last_tree.left = TreeNode(None)
				tree_stack.append(last_tree)
				tree_stack.append(last_tree.left)
			elif current == ',':
				last_tree = tree_stack.pop()
				if last_tree.val is None:
					last_tree = tree_stack.pop()
				last_tree.right = TreeNode(None)
				tree_stack.append(last_tree)
				tree_stack.append(last_tree.right)
			else:
				value.append(current)

		return last_tree

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
