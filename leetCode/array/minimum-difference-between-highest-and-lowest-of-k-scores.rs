// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores
impl Solution {
    pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32 {
        if nums.len() == 1 {
            return 0;
        }

        let mut nums = nums;
        nums.sort();

        // println!("nums:{nums:?}");

        let mut cur = 0;
        for i in 1..(k as usize) {
            cur += nums[i] - nums[i - 1];
            // println!("cur:{cur}, i:{i}, nums[i]:{}, nums[i - 1]:{}", nums[i], nums[i - 1]);
        }

        let mut resp = cur;
        // println!("resp:{resp}, cur:{cur}");
        for i in (k as usize)..nums.len() {
            cur = cur - nums[i - k as usize + 1] + nums[i - k as usize] + nums[i] - nums[i - 1];
            // println!(
            //     "cur:{cur}, i:{i}, nums[i - k as usize + 1]:{}, nums[i - k as usize]:{}, nums[i]:{}, nums[i - 1]:{}",
            //     nums[i - k as usize + 1], nums[i - k as usize], nums[i], nums[i - 1],
            // );
            if cur < resp {
                resp = cur;
            }
            // println!("resp:{resp}, cur:{cur}");
        }

        resp
    }
}
