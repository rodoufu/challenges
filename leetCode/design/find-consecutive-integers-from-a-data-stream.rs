// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream
use std::{
    collections::HashMap,
    vec::Vec,
};

struct DataStream {
    value: i32,
    k: usize,

    count: HashMap<i32, usize>,
    last_k: Vec<i32>,
    start_last_k: usize,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl DataStream {

    fn new(value: i32, k: i32) -> Self {
        Self {
            value,
            k: k as usize,
            count: Default::default(),
            last_k: Default::default(),
            start_last_k: 0,
        }
    }
    
    fn consec(&mut self, num: i32) -> bool {
        *self.count.entry(num).or_insert(0) += 1;
        if self.last_k.len() < self.k {
            self.last_k.push(num);
        } else {
            *self.count.entry(self.last_k[self.start_last_k]).or_insert(0) -= 1;
            self.last_k[self.start_last_k] = num;
        }
        self.start_last_k = (self.start_last_k + 1) % self.k;
        
        *self.count.entry(self.value).or_insert(0) == self.k
    }
}

/**
 * Your DataStream object will be instantiated and called as such:
 * let obj = DataStream::new(value, k);
 * let ret_1: bool = obj.consec(num);
 */
 
