// https://leetcode.com/problems/kth-largest-element-in-a-stream
use std::collections::BinaryHeap;
use std::cmp::Reverse;

struct KthLargest {
    elements: BinaryHeap<Reverse<i32>>,
    k: i32,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl KthLargest {

    fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut resp = Self {
            k,
            elements: Default::default(),
        };

        for num in nums {
            resp.add(num);
        }
        resp
    }
    
    fn add(&mut self, val: i32) -> i32 {
        if self.elements.len() < self.k as usize
            || self.elements.peek().copied().unwrap_or_default().0 < val {
            self.elements.push(Reverse(val));
        }
        while self.elements.len() > self.k as usize {
            self.elements.pop();
        }

        self.elements.peek().copied().unwrap_or_default().0
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * let obj = KthLargest::new(k, nums);
 * let ret_1: i32 = obj.add(val);
 */
