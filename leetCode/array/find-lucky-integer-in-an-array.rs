// https://leetcode.com/problems/find-lucky-integer-in-an-array
use std::collections::HashMap;

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        let mut num_count = HashMap::new();

        for x in arr {
            *num_count.entry(x).or_insert(0) += 1;
        }

        let mut found = None;
        for (num, count) in num_count {
            if num == count {
                if found.is_none() || found.unwrap() < num {
                    found = Some(num);
                }
            }
        }

        found.unwrap_or(-1)
    }
}
