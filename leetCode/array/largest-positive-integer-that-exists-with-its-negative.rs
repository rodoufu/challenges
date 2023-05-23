// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative
use std::collections::{
    HashSet,
    BTreeSet,
};

impl Solution {
    pub fn find_max_k(nums: Vec<i32>) -> i32 {
        let mut negative = BTreeSet::new();
        let mut positive = HashSet::new();
        for k in nums {
            if k > 0 {
                positive.insert(k);
            } else {
                negative.insert(k);
            }
        }

        // println!("negative: {negative:?}, positive:{positive:?}");
        for k in negative {
            if positive.contains(&-k) {
                return -k;
            }
        }
        -1
    }
}
