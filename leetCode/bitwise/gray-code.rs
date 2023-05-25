// https://leetcode.com/problems/gray-code/
use std::collections::HashSet;

impl Solution {
    pub fn gray_code(n: i32) -> Vec<i32> {
        let mut num_used = HashSet::new();
        let mut resp = Vec::new();

        let mut last = 0_u64;
        num_used.insert(last);
        resp.push(last as i32);
        let mut should_try = true;

        while should_try {
            should_try = false;
            for i in 0..n {
                let mask = 1u64 << i;
                let new_num = last ^ mask;
                //println!("i:{i}, last:{last}-{last:08b}, mask:{mask}-{mask:08b}, new_num:{new_num}-{new_num:08b}");
                if !num_used.contains(&new_num) {
                    last = new_num;
                    num_used.insert(last);
                    resp.push(last as i32);
                    should_try = true;
                    break;
                }
            }
        }

        resp        
    }
}
