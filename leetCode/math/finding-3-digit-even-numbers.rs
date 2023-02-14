// https://leetcode.com/problems/finding-3-digit-even-numbers/
use std::collections::BTreeSet;
impl Solution {
    pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
        let mut found = BTreeSet::new();
        let len_d = digits.len();

        for i in 0..len_d {
            if digits[i] == 0 {
                continue
            }
            for j in 0..len_d {
                if j == i {
                    continue
                }
                for k in 0..len_d {
                    if k == j || k == i || digits[k] % 2 == 1 {
                        continue
                    }

                    found.insert(100 * digits[i] + 10 * digits[j] + digits[k]);
                }
            }
        }

        found.into_iter().collect::<Vec<i32>>()
    }
}
