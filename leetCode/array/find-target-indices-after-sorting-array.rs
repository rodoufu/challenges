// https://leetcode.com/problems/find-target-indices-after-sorting-array/
impl Solution {
    pub fn target_indices(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut nums = nums;
        nums.sort();
        nums.iter().enumerate().filter(|(_, x)| **x == target).map(|(i, _)| i as i32).collect()
    }
}
