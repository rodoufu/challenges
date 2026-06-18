// https://leetcode.com/problems/climbing-stairs
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 3 {
            return n;
        }
        let mut first = 1;
        let mut second = 2;

        for _ in 2..n {
            let temp = first + second;
            first = second;
            second = temp;
        }

        second
    }
}
