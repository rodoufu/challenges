// https://leetcode.com/problems/minimize-string-length/
use std::collections::HashSet;
impl Solution {
    pub fn minimized_string_length(s: String) -> i32 {
        let mut letters = HashSet::new();
        for letter in s.chars() {
            letters.insert(letter);
        }
        letters.len() as i32
    }
}
