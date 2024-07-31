// https://leetcode.com/problems/circular-array-loop/
use std::collections::HashSet;
impl Solution {
    pub fn circular_array_loop(nums: Vec<i32>) -> bool {
        let mut visited = HashSet::<i32>::new();
        let n = nums.len() as i32;
        for i in 0..n {
            println!("i:{i}");
            if visited.contains(&i) {
                continue;
            }

            let mut in_loop = HashSet::from([i]);
            let mut x = i;
            let is_positive = nums[i as usize] > 0;
            loop {
                if (is_positive && nums[x as usize] < 0) || (!is_positive && nums[x as usize] > 0) {
                    break;
                } 
                let pos = (((x + nums[x as usize]) % n) + n) % n;
                // println!("x:{x}, pos:{pos}");

                if pos == x {
                    visited.extend(&in_loop);
                    break;
                }
                x = pos;
                if in_loop.contains(&pos) {
                    // println!("visited:{visited:?}, in_loop:{in_loop:?} pos:{pos} ->");
                    return true;
                }
                in_loop.insert(pos);
            }
        }

        false
    }
}
