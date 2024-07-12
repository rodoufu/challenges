/// https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/
impl Solution {
    pub fn minimum_sum(nums: Vec<i32>) -> i32 {
        let mut resp = -1;
        let n = nums.len();

        for i in 0..n-2 {
            for j in (i+1)..n-1 {
                for k in (j+1)..n {
                    if nums[i] < nums[j] && nums[j] > nums[k] {
                        if resp == -1 || nums[i] + nums[j] + nums[k] < resp {
                            resp = nums[i] + nums[j] + nums[k];
                        }
                    }
                }
            }
        }

        resp
    }
}
