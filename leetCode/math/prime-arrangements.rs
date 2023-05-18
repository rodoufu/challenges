// https://leetcode.com/problems/prime-arrangements/
const to_mod: u128 = 1000000000 + 7;
impl Solution {
    fn is_prime(n: u128) -> bool {
        if n <= 2 {
            return n == 2;
        }
        if n % 2 == 0 {
            return false;
        }
        let mut x = 3;
        let last = (f64::sqrt(n as f64) + 1.0) as u128;
        while x <= last {
            if n % x == 0 {
                return false;
            }
            x += 2;
        }
        true
    }

    pub fn num_prime_arrangements(n: i32) -> i32 {
        let n: u128 = n as u128;
        let number_of_primes = (1..n+1).filter(|x| Solution::is_prime(*x)).count() as u128;
        
        let mut resp = 1u128;
        for x in (1..number_of_primes + 1).chain((1..n - number_of_primes + 1)) {
            resp = (resp * x) % to_mod;
        }

        resp as i32
    }
}
