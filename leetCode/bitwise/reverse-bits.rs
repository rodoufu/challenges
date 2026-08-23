// https://leetcode.com/problems/reverse-bits
impl Solution {
    pub fn reverse_bits(mut n: i32) -> i32 {
        let mut n = n as u32;
        let mut resp = 0u32;

        let mut a = 0u32;
        while n > 0 {
            // println!("n: {n}, a: {a}, resp: {resp}");
            resp = 2 * resp + (n % 2);
            n /= 2;
            a += 1;
        }
        // println!("n: {n}, a: {a}, resp: {resp}");

        //if resp != 0 {
        //} else {
        //    resp as i32
        //}
        (resp << 32 - a) as i32
    }
}
