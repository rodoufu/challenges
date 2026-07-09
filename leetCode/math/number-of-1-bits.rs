// https://leetcode.com/problems/number-of-1-bits
impl Solution {
    pub fn hamming_weight(mut n: i32) -> i32 {
        let mut count = 0;

        while n > 0 {
            // println!("n: {n}");
            if n & 1 == 1 {
                count += 1;
            }

            n >>= 1;
        }

        count
    }
}
