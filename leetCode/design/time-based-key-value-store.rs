// https://leetcode.com/problems/time-based-key-value-store/
use std::collections::{
    BTreeMap,
    HashMap,
};

#[derive(Default)]
struct TimeMap {
    data: HashMap<String, BTreeMap<i32, String>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TimeMap {

    fn new() -> Self {
        Self::default()
    }
    
    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.data.entry(key).or_default().insert(timestamp, value);
    }
    
    fn get(&self, key: String, timestamp: i32) -> String {
        if let Some(tree) = self.data.get(&key) {
            tree.range(..timestamp+1).next_back().map(|x| x.1.clone()).unwrap_or_else(String::default)
        } else {
            String::default()
        }
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */
