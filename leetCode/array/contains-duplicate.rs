// https://leetcode.com/problems/contains-duplicate/
use std::collections::HashSet;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let nums_len = nums.len();
        let temp = nums.into_iter().collect::<HashSet<_>>();

        temp.len() != nums_len
    }
}
