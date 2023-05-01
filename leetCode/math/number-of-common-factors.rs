// https://leetcode.com/problems/number-of-common-factors/
impl Solution {
    pub fn common_factors(a: i32, b: i32) -> i32 {
        let mut resp = 1;
        let smaller = if a < b { a } else { b };

        for x in 2..smaller+1 {
            if a % x == 0 && b % x == 0 {
                resp += 1;
            }
        }

        resp
    }
}
