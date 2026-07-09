// https://leetcode.com/problems/single-number
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut value = nums[0];
        for i in 1..nums.len() {
            value ^= nums[i];
        }

        value
    }
}
