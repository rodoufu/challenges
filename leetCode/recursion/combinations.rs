// https://leetcode.com/problems/combinations
use std::{
    cell::RefCell,
    collections::HashSet,
    hash::{Hash, Hasher},
    rc::Rc,
};

impl Solution {
    fn comb(n: i32, k: i32, output: Rc<RefCell<Vec<Vec<i32>>>>, temp: Rc<RefCell<Vec<i32>>>, start: i32) {
        if temp.borrow().len() == k as usize {
            output.borrow_mut().push(temp.borrow().to_vec());
            return;
        }
        for i in start..n+1 {
            temp.borrow_mut().push(i);
            Solution::comb(n, k, output.clone(), temp.clone(), i+1);
            temp.borrow_mut().pop();
        }
    }

    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let resp = Rc::new(RefCell::new(Vec::new()));
        Solution::comb(n, k, resp.clone(), Rc::new(RefCell::new(Vec::new())), 1);

        resp.take()
    }
}
