// https://leetcode.com/problems/invert-binary-tree
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let Some(root) = root else {
            return None;
        };
        let (left, right) = {
            let mut node = root.borrow_mut();
            let left = Self::invert_tree(node.left.take());
            let right = Self::invert_tree(node.right.take());
                (left, right)
        };

        root.borrow_mut().left = right;
        root.borrow_mut().right = left;

        Some(root)
    }
}
