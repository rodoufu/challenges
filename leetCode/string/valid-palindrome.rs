// https://leetcode.com/problems/valid-palindrome/
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let mut input = s.to_lowercase()
            .chars()
            .filter(|x| x.is_alphanumeric())
            .collect::<Vec<_>>();
        // println!("input: {input:?}");
        let input_len = input.len();
        for i in 0..input_len/2 {
            if input[i] != input[input_len-i-1] {
                return false;
            }
        }

        true
    }
}
