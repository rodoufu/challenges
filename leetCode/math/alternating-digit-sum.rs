// https://leetcode.com/problems/alternating-digit-sum/
impl Solution {
    pub fn alternate_digit_sum(n: i32) -> i32 {
        let mut positive = 0;
        let mut negative = 0;

        let mut count = 0;
        let mut signal = 1;
        let mut n = n;
        while n > 0 {
            positive += signal * (n % 10);
            negative -= signal * (n % 10);

            n /= 10;
            signal *= -1;
            count += 1;
        }

        if count % 2 == 1 {
            return positive
        }
        negative
    }
}
