// https://leetcode.com/problems/four-divisors
use std::collections::HashMap;

impl Solution {
    fn sum_of_divisors(n: i32) -> i32 {
        let mut sum = n + 1;
        let mut count = 2;

        for x in 2..(f64::sqrt(n as f64) as i32 + 1) {
            if n % x == 0 {
                sum += x;
                count += 1;
                if x != n / x {
                    sum += n / x;
                    count += 1;
                }
            }
            if count > 4 {
                break;
            }
        }

        if count == 4 {
            sum
        } else {
            0
        }
    }

    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        let mut num_sum_div = HashMap::new();
        let mut sum = 0;

        for x in nums {
            if let Some(sum_div) = num_sum_div.get(&x) {
                sum += sum_div;
            } else {
                let val = Solution::sum_of_divisors(x);
                sum += val;
                num_sum_div.insert(x, val);
            }
        }

        sum
    }
}
