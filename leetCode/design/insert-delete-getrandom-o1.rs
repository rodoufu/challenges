// https://leetcode.com/problems/insert-delete-getrandom-o1
use std::collections::HashMap;
use rand::prelude::*;

#[derive(Default, Debug)]
struct RandomizedSet {
    value_to_position: HashMap<i32, usize>,
    items: Vec<i32>,
    rng: rand::rngs::ThreadRng,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        Default::default()
    }
    
    fn insert(&mut self, val: i32) -> bool {
        if self.value_to_position.contains_key(&val) {
            return false;
        }
        self.items.push(val);
        self.value_to_position.insert(val, self.items.len() - 1);

        // println!("insert: {val} - {self:?}");
        true
    }
    
    fn remove(&mut self, val: i32) -> bool {
        let Some(pos) = self.value_to_position.remove(&val) else {
            return false;
        };
        self.items[pos] = self.items[self.items.len() - 1];
        self.items.pop();
        if !self.items.is_empty() && pos < self.items.len() {
            self.value_to_position.insert(self.items[pos], pos);
        }

        // println!("remove: {val} - {self:?}");
        true
    }
    
    fn get_random(&mut self) -> i32 {
        // println!("get_random - {self:?}");
        self.items.choose(&mut self.rng).copied().unwrap_or_default()
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */
