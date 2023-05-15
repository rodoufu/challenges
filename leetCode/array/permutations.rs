// https://leetcode.com/problems/permutations
use std::{
    cell::RefCell,
    collections::VecDeque,
    rc::Rc,
};

impl Solution {
    fn gen_permute(added: Rc<RefCell<VecDeque<i32>>>, to_add: Rc<RefCell<VecDeque<i32>>>) -> Vec<Vec<i32>> {
        // println!("added:{added:?}, to_add:{to_add:?}");
        if to_add.borrow().is_empty() {
            return vec![added.borrow().iter().copied().collect()];
        }

        let mut resp = Vec::new();
        let len_to_add = to_add.borrow().len();
        for i in 0..len_to_add {
            // println!("{i}/{len_to_add} -> added:{added:?}, to_add:{to_add:?}");
            let front = to_add.borrow_mut().pop_front().unwrap();
            added.borrow_mut().push_back(front);
            resp.append(&mut Solution::gen_permute(added.clone(), to_add.clone()));
            
            to_add.borrow_mut().push_back(front);
            added.borrow_mut().pop_back();
        }

        resp
    }

    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        Solution::gen_permute(Rc::new(RefCell::new(VecDeque::new())), Rc::new(RefCell::new(nums.into_iter().collect())))
    }
}
