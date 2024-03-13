// https://leetcode.com/problems/remove-trailing-zeros-from-a-string/
impl Solution {
    pub fn remove_trailing_zeros(num: String) -> String {
        let mut is_zero = true;
        let mut resp = Vec::new();
        for it in num.chars().rev() {
            if !is_zero || it != '0' {
                is_zero = false;
                resp.push(it);
            }
        }

        resp.iter().rev().collect()
    }
}
