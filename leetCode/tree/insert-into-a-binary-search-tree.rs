// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    fn insert_in_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) {
        let root = root.unwrap();
        if val < root.borrow().val {
            if root.borrow().left.is_none() {
                root.borrow_mut().left = Some(Rc::new(RefCell::new(TreeNode{
                    val,
                    left: None,
                    right: None,
                })));
            } else {
                Solution::insert_in_bst(root.borrow().left.clone(), val);
            }
        } else {
            if root.borrow().right.is_none() {
                root.borrow_mut().right = Some(Rc::new(RefCell::new(TreeNode{
                    val,
                    left: None,
                    right: None,
                })));
            } else {
                Solution::insert_in_bst(root.borrow().right.clone(), val);
            }
        }
    }

    pub fn insert_into_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: None,
                right: None,
            })));
        }
        Solution::insert_in_bst(root.clone(), val);

        root
    }
}
