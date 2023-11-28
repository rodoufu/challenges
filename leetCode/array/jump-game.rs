// https://leetcode.com/problems/jump-game
impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let n_len = nums.len();
        let mut count = vec![false; n_len];
        count[0] = true;

        // println!("nums: {nums:?}");

        for i in 0..n_len-1 {
            // println!("n_len: {n_len}, count: {count:?}, i: {i}");
            if !count[i] {
                continue;
            }
            for j in 1..(nums[i] as usize)+1 {
                if i + j >= n_len {
                    break;
                }
                count[i + j] = true;
                if i + j == n_len - 1 {
                    break;
                }
            }
        }

        // println!("n_len: {n_len}, count: {count:?}");

        count[n_len - 1]
    }
}
