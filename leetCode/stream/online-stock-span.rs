// https://leetcode.com/problems/online-stock-span
use std::collections::{BTreeMap, HashMap, HashSet};
use std::ops::Bound::{Excluded, Included, Unbounded};

#[derive(Debug)]
struct StockSpanner {
    price_pos: BTreeMap<i32, i32>,
    len: i32,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {
    fn new() -> Self {
        Self {
            price_pos: Default::default(),
            len: 0,
        }
    }
    
    fn next(&mut self, price: i32) -> i32 {
        //println!("next {self:?}");
        let mut max_idx = 0;
        let mut subtract = 0;
        for (_, id) in self.price_pos.range((Excluded(price), Unbounded)) {
            subtract = -1;
            if *id > max_idx {
                max_idx = *id;
            }
        }
        self.price_pos.insert(price, self.len);
        self.len += 1;

        if self.len == 1 {
            return 1;
        }
        self.len - max_idx + subtract
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * let obj = StockSpanner::new();
 * let ret_1: i32 = obj.next(price);
 */
 
