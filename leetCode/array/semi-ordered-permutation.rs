// https://leetcode.com/problems/semi-ordered-permutation/
impl Solution {
    pub fn semi_ordered_permutation(nums: Vec<i32>) -> i32 {
        let one_idx = nums.iter().enumerate().filter_map(
            |(i, x)| if *x == 1 { Some(i) } else { None }
        ).next().unwrap() as i32;
        let n = nums.len() as i32;
        let n_idx = nums.iter().enumerate().filter_map(
            |(i, x)| if *x == n { Some(i) } else { None }
        ).next().unwrap() as i32;

        if one_idx < n_idx {
            one_idx + n - n_idx - 1
        } else {
            one_idx + n - n_idx - 2
        }
    }
}
