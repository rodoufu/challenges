// https://leetcode.com/problems/three-divisors/
impl Solution {
    pub fn is_three(n: i32) -> bool {
        if n < 3 {
            return false;
        }
        if n == 4 {
            return true;
        }
        let n_sqrt = ((n as f64).sqrt() + 0.5) as i32;
        for i in 2..n_sqrt {
            if n % i == 0 {
                return false;
            }
        }
        n_sqrt * n_sqrt == n
    }
}
