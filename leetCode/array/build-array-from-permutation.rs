// https://leetcode.com/problems/build-array-from-permutation/
impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        let mut resp = Vec::with_capacity(nums.len());

        for i in 0..nums.len() {
            resp.push(nums[nums[i] as usize]);
        }

        resp
    }
}
