/// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut resp: i64 = 0;
        let n = nums.len();

        for i in 0..(n-2) {
            for j in (i+1)..(n-1) {
                for k in (j+1)..n {
                    let temp = (nums[i] as i64 - nums[j] as i64) * nums[k] as i64;
                    if temp > resp {
                        resp = temp;
                    }
                }
            }
        }

        resp
    }
}
