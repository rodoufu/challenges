// https://leetcode.com/problems/number-of-arithmetic-triplets/
impl Solution {
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let len_n = nums.len();
        let mut resp = 0;
        for i in 0..len_n {
            for j in i+1..len_n {
                if nums[j] - nums[i] > diff {
                    break;
                }
                if nums[j] - nums[i] < diff {
                    continue;
                }
                for k in j+1..len_n {
                    if nums[k] - nums[j] > diff {
                        break;
                    }
                    if nums[k] - nums[j] < diff {
                        continue;
                    }
                    resp += 1;
                }
            }
        }

        resp
    }
}
