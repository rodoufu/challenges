// https://leetcode.com/problems/path-sum/

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
    fn has_path_sum_so_far(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32, so_far: i32) -> bool {
        let root = root.unwrap();
        if root.borrow().left.is_none() && root.borrow().right.is_none() {
            return so_far + root.borrow().val == target_sum;
        }
        if root.borrow().left.is_some() {
            if Solution::has_path_sum_so_far(root.borrow().left.clone(), target_sum, so_far + root.borrow().val) {
                return true;
            }
        }
        if root.borrow().right.is_some() {
            if Solution::has_path_sum_so_far(root.borrow().right.clone(), target_sum, so_far + root.borrow().val) {
                return true;
            }
        }
        false
    }

    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        if root.is_none() {
            return false;
        }
        Solution::has_path_sum_so_far(root, target_sum, 0)
    }
}
