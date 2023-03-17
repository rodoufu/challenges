// https://leetcode.com/problems/find-all-anagrams-in-a-string/
use std::collections::HashMap;

#[derive(Debug)]
struct CountLetters {
    letter_count: HashMap<char, u32>,
    len: usize,
}

impl Default for CountLetters {
    fn default() -> Self {
        Self {
            letter_count: Default::default(),
            len: 0,
        }
    }
}

impl From<String> for CountLetters {
    fn from(value: String) -> Self {
        let mut letter_count = HashMap::new();
        for letter in value.chars() {
            *letter_count.entry(letter).or_default() += 1;
        }
        Self {
            letter_count,
            len: value.len(),
        }
    }
}

impl CountLetters {
    fn add_letter(&mut self, letter: char) {
        *self.letter_count.entry(letter).or_default() += 1;
        self.len += 1;
    }
    fn remove_letter(&mut self, letter: char) {
        *self.letter_count.entry(letter).or_default() -= 1;
        self.len -= 1;
    }
    fn is_anagram(&self, other: &CountLetters) -> bool {
        if self.len != other.len {
            return false;
        }
        for (letter_o, count_o) in &other.letter_count {
            if let Some(count_s) = self.letter_count.get(letter_o) {
                if count_o != count_s {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        true
    }
}

impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let count_p: CountLetters = p.into();
        let mut count_it = CountLetters::default();
        //println!("p: {:?}", count_p);

        let mut resp = Vec::new();
        let s_chars: Vec<char> = s.chars().collect();
        for i in 0..s.len() {
            count_it.add_letter(s_chars[i]);
            //println!("it: {:?}", count_it);
            if i >= count_p.len {
                count_it.remove_letter(s_chars[i - count_p.len]);
            }
            //println!("it: {:?}", count_it);

            if count_it.is_anagram(&count_p) {
                resp.push((i - count_p.len + 1) as i32);
            }
        }
        
        resp
    }
}
