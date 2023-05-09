// https://leetcode.com/problems/permutation-in-string
use std::collections::HashMap;
#[derive(Default, Debug)]
struct Permutation {
    letter_count: HashMap<char, usize>,
}

impl<T: Into<String>> From<T> for Permutation {
    fn from(value: T) -> Self {
        let mut letter_count = HashMap::new();
        for letter in value.into().chars() {
            *letter_count.entry(letter).or_default() += 1;
        }
        Self {
            letter_count,
        }
    }
}

impl Permutation {
    fn is_permutation(&self, other: &Self) -> bool {
        if self.letter_count.len() != other.letter_count.len() {
            return false;
        }
        for (letter, count) in &self.letter_count {
            if let Some(other_count) = other.letter_count.get(letter) {
                if *count != *other_count {
                    return false;
                }
            } else {
                return false;
            }
        }
        true
    }

    fn add(&mut self, letter: char) {
        *self.letter_count.entry(letter).or_default() += 1;
    }
    
    fn remove(&mut self, letter: char) {
        let entry = self.letter_count.entry(letter).or_default();
        *entry -= 1;
        if *entry == 0 {
            self.letter_count.remove(&letter);
        }
    }
}

impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        if s2.len() < s1.len() {
            return false;
        }
        let s1_permutaiton = Permutation::from(&s1);
        if s1.len() == s2.len() {
            return s1_permutaiton.is_permutation(&Permutation::from(s2));
        }

        let s2_len = s2.len();
        let s1_len = s1.len();
        let s2_chars = s2.chars().collect::<Vec<char>>();

        let mut it_permutation = Permutation::from(&s2[0..s1_len]);
        // println!("initial: {}, it_permutation: {it_permutation:?}", &s2[0..s1_len]);
        if s1_permutaiton.is_permutation(&it_permutation) {
            return true;
        }

        for start in 1..s2_len-s1_len+1 {
            let old_char = s2_chars[start - 1];
            let new_char = s2_chars[start + s1_len - 1];
            it_permutation.remove(old_char);
            it_permutation.add(new_char);
            // println!("old_char:{old_char}, new_char:{new_char}, it_permutation: {it_permutation:?}");
            if s1_permutaiton.is_permutation(&it_permutation) {
                // println!("s1_permutaiton:{s1_permutaiton:?}, it_permutation: {it_permutation:?}");
                return true;
            }
        }

        false
    }
}
