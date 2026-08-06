// https://leetcode.com/problems/happy-number
impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut slow = Self::sum_digits(n);
        let mut fast = Self::sum_digits(Self::sum_digits(n));

        while slow != fast {
            slow = Self::sum_digits(slow);
            fast = Self::sum_digits(Self::sum_digits(fast));
        }

        slow == 1
    }

    #[inline]
    fn sum_digits(mut n: i32) -> i32 {
        let mut sum = 0;

        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }

        sum
    }
}
