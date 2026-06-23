// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
use std::collections::HashMap;

impl Solution {
    pub fn min_cost_to_move_chips(position: Vec<i32>) -> i32 {
        let mut pos_count = HashMap::new();
        for pos in &position {
            *pos_count.entry(pos).or_default() += 1;
        }
        let mut more_elements = 0;
        let mut more_elements_val = 0;
        for (pos, count) in &pos_count {
            if *count > more_elements_val {
                more_elements_val = *count;
                more_elements = **pos;
            }
        }

        let temp = position.iter().map(|x| (if *x > more_elements { x - more_elements } else { more_elements - x}) % 2).sum();
        let temp0 = position.iter().map(|x| (if *x > (more_elements - 1) { x - more_elements + 1 } else { more_elements - 1 - x}) % 2).sum();
        let temp1 = position.iter().map(|x| (if *x > (more_elements + 1) { x - more_elements - 1 } else { more_elements + 1 - x}) % 2).sum();
        // println!("pos_count:{pos_count:?}, more_elements:{more_elements}, more_elements_val:{more_elements_val}, temp:{temp:?}, temp0:{temp0:?}, temp1:{temp1:?}");
        *[temp, temp0, temp1].iter().min().unwrap()
    }
}
