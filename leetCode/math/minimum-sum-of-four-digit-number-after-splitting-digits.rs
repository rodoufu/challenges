// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
impl Solution {
    pub fn minimum_sum(num: i32) -> i32 {
        let mut digits = Vec::new();
        let mut resp = 999999;

        let mut num = num;
        for i in 0..4 {
            digits.push(num % 10);
            num /= 10;
        }

        for i in 0..4 {
            for j in 0..4 {
                if j == i {
                    continue
                }
                for k in 0..4 {
                    if k == i || k == j {
                        continue
                    }
                    for l in 0..4 {
                        if l == i || l == j || l == k {
                            continue
                        }

                        let val = 10 * digits[i] + digits[j] + 10 * digits[k] + digits[l];
                        if val < resp {
                            resp = val
                        }
                    }
                }
            }
        }

        resp
    }
}
