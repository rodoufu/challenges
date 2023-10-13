// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences
use std::collections::{
    HashMap,
    HashSet,
};

impl Solution {
    pub fn are_occurrences_equal(s: String) -> bool {
        let mut letter_count = HashMap::<char, usize>::new();
        for letter in s.chars() {
            *letter_count.entry(letter).or_default() += 1;
        }
        let counts: HashSet<_> = letter_count.values().collect();
        counts.len() == 1
    }
}
