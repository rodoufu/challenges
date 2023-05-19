// https://leetcode.com/problems/symmetric-tree

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
    fn are_symmetric(left: Option<Rc<RefCell<TreeNode>>>, right: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (left, right) {
            (None, None) => true,
            (None, Some(_)) => false,
            (Some(_), None) => false,
            (Some(left), Some(right)) => {
                if left.borrow().val != right.borrow().val {
                    return false;
                }
                Solution::are_symmetric(left.borrow().left.clone(), right.borrow().right.clone()) && Solution::are_symmetric(left.borrow().right.clone(), right.borrow().left.clone())
            }
        }
    }

    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            None => true,
            Some(root) => Solution::are_symmetric(root.borrow().left.clone(), root.borrow().right.clone()),
        }    
    }
}
