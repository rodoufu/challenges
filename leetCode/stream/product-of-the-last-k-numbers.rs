// https://leetcode.com/problems/product-of-the-last-k-numbers/
use std::collections::BTreeSet;
use std::ops::Bound::{Excluded, Included};

#[derive(Debug)]
struct ProductOfNumbers {
    products: Vec<i64>,
    zero_index: BTreeSet<usize>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ProductOfNumbers {
    fn new() -> Self {
        Self {
            products: vec![1],
            zero_index: Default::default(),
        }
    }
    
    fn add(&mut self, num: i32) {
        let val = num as i64 * self.products.last().map(|x| if *x == 0 { &1 } else { x }).unwrap_or(&1);
        self.products.push(val);
        if val == 0 {
            self.zero_index.insert(self.products.len() - 1);
        }
        // println!("add num:{num}, {self:?}");
    }
    
    fn get_product(&self, k: i32) -> i32 {
        // println!("get_product k:{k}, {self:?}");
        let initial_pos = self.products.len() - k as usize - 1;
        let mut zeros = self.zero_index.range((Excluded(initial_pos), Included(self.products.len())));
        if zeros.next().is_some() {
            // println!("has zeros");
            0
        } else if let Some(first) = self.products.get(initial_pos).copied() {
            if first == 0 {
                // println!("first zero");
                self.products.last().copied().unwrap() as i32
            } else {
                // println!("first different");
                (self.products.last().copied().unwrap() / first) as i32
            }
        } else {
            // println!("no first");
            self.products.last().copied().unwrap_or(1) as i32
        }
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * let obj = ProductOfNumbers::new();
 * obj.add(num);
 * let ret_2: i32 = obj.get_product(k);
 */
