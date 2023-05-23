// https://leetcode.com/problems/count-distinct-numbers-on-board/
use std::collections::HashSet;
impl Solution {
    pub fn distinct_integers(n: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        let mut nums = HashSet::from([n]);
        for _ in 0..1_000_000_000 {
            let mut temp = HashSet::new();
            for x in &nums {
                if *x > 2 {
                    temp.insert(*x - 1);
                }
            }
            let nums_len = nums.len();
            for y in temp {
                nums.insert(y);
            }
            if nums.len() == nums_len {
                break;
            }
        }

        // println!("nums: {nums:?}");
        nums.len() as i32
    }
}
