// https://leetcode.com/problems/count-integers-with-even-digit-sum/
impl Solution {
    fn sum_digits(num: i32) -> i32 {
        let mut num = num;
        let mut sum = 0;

        while num > 0 {
            sum += num % 10;
            num /= 10;
        }

        sum
    }

    pub fn count_even(num: i32) -> i32 {
        if num <= 1 {
            return 0;
        }

        let mut resp = 0;
        for i in 2..(num+1) {
            if Solution::sum_digits(i) % 2 == 0 {
                resp += 1;
            }
        }
        resp
    }
}
