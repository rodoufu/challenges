// https://leetcode.com/problems/jump-game-ii/
impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let n_len = nums.len();
        let mut count = vec![std::i32::MAX; n_len];
        count[0] = 0;

        // println!("nums: {nums:?}");

        for i in 0..n_len-1 {
            // println!("n_len: {n_len}, count: {count:?}, i: {i}");
            for j in 1..(nums[i] as usize)+1 {
                if i + j >= n_len {
                    break;
                }
                count[i + j] = i32::min(count[i + j], count[i] + 1);
                if i + j == n_len - 1 {
                    break;
                }
            }
        }

        // println!("n_len: {n_len}, count: {count:?}");

        count[n_len - 1]
    }
}
