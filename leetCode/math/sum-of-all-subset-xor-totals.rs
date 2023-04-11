// https://leetcode.com/problems/sum-of-all-subset-xor-totals/
impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        let mut resp = 0;

        for i in 0..i32::pow(2, nums.len() as u32) {
            let mut cur_xor = 0;
            //let mut temp = Vec::new();

            for j in 0..nums.len() {
                if i & (1 << j) & ((1 << (j + 1)) - 1) > 0 {
                    cur_xor ^= nums[j];
                    //temp.push(nums[j]);
                }
            }
            //println!("{temp:?}");

            resp += cur_xor;
        }

        resp
    }
}
