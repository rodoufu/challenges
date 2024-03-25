// https://leetcode.com/problems/maximum-number-of-words-you-can-type/
use std::{
    collections::HashSet,
    iter::FromIterator,
};

impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        let broken_letters = HashSet::<char>::from_iter(broken_letters.chars());
        text.split(' ').map(
            |word| 
            if word.chars().any(
                |letter| 
                broken_letters.contains(&letter)
            ) { 0 } else { 1 }
        ).sum()
    }
}
