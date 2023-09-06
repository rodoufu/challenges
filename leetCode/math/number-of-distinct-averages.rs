// https://leetcode.com/problems/number-of-distinct-averages/
use std::collections::{
    HashSet,
    VecDeque,
};

impl Solution {
    pub fn distinct_averages(nums: Vec<i32>) -> i32 {
        let mut averages = HashSet::new();
        let mut nums = nums;
        nums.sort();
        let mut nums = nums.into_iter().collect::<VecDeque<i32>>();
        
        while !nums.is_empty() {
            let avg = (nums.pop_front().unwrap() as f64 + nums.pop_back().unwrap() as f64) / 2.0;
            averages.insert(format!("{avg:.5}"));
        }
        
        averages.len() as i32
    }
}
