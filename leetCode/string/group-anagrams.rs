// https://leetcode.com/problems/group-anagrams/
use std::collections::{
    BTreeMap,
    HashMap,
};

#[derive(Hash, PartialEq, Eq)]
struct CountLetters {
    data: BTreeMap<char, u32>,
}

impl From<&String> for CountLetters {
    fn from(word: &String) -> Self {
        let mut data = BTreeMap::new();
        for letter in word.chars() {
            *data.entry(letter).or_default() += 1;
        }
        Self {
            data,
        }
    }
}

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut anagram_word: HashMap<CountLetters, Vec<String>> = HashMap::new();
        for word in strs {
            let count = CountLetters::from(&word);
            anagram_word.entry(count).or_default().push(word);
        }
        
        anagram_word.into_iter().map(|(_, x)| x).collect()
    }
}
