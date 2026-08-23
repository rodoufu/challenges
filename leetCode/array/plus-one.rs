// https://leetcode.com/problems/plus-one
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut plus_one = 1;

        for digit in digits.iter_mut().rev() {
            *digit += 1;
            if *digit > 9 {
                *digit = 0;
                plus_one = 1;
            } else {
                plus_one = 0;
                break;
            }
        }

        std::iter::repeat(1).take(plus_one).chain(digits).collect()
    }
}
