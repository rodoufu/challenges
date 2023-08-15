// https://leetcode.com/problems/count-pairs-of-similar-strings/
use std::{
    collections::{
        HashMap,
        HashSet,
    },
    iter::FromIterator,
};

#[derive(Debug)]
struct Word {
    //letter_count: HashMap<char, usize>,
    letters: HashSet<char>,
}

impl From<String> for Word {
    fn from(word: String) -> Self {
        // let mut letter_count = HashMap::new();
        // for letter in word.chars() {
        //     *letter_count.entry(letter).or_default() += 1;
        // }
        // Self {
        //     letter_count,
        // }

        Self {
            letters: HashSet::from_iter(word.chars()),
        }
    }
}

impl Word {
    fn contains(&self, other: &Self) -> bool {
        for letter in &other.letters {
            if !self.letters.contains(letter)  {
                return false;
            }
        }
        
        true
    }
    
    fn is_similar(&self, other: &Self) -> bool {
        self.contains(other) && other.contains(self)
    }
}

impl Solution {
    pub fn similar_pairs(words: Vec<String>) -> i32 {
        let words = words.into_iter().map(Word::from).collect::<Vec<Word>>();
        let mut count = 0;
        let len_w = words.len();
        
        for i in 0..len_w-1 {
            for j in i+1..len_w {
                if words[i].is_similar(&words[j]) {
                    // println!("{:?} is similar to {:?}", words[i], words[j]);
                    count += 1;
                }
            }
        }
        
        count
    }
}
