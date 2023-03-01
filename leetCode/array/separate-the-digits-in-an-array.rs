// https://leetcode.com/problems/separate-the-digits-in-an-array/
impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        let mut resp = Vec::new();

        for mut num in nums {
            let mut digits = Vec::new();
            while num > 0 {
                digits.push(num % 10);
                num /= 10;
            }
            resp.extend(digits.iter().rev());
        }

        resp
    }
}
