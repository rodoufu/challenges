// https://leetcode.com/problems/implement-magic-dictionary/
use std::collections::HashMap;

struct CountLetters{
    count: HashMap<char, u32>,
    word: Vec<char>,
}

impl CountLetters {
    fn new(word: String) -> Self {
        let mut resp = HashMap::new();
        for x in word.chars() {
            *resp.entry(x).or_insert(0) += 1;
        }

        Self {
            count: resp,
            word: word.chars().collect(),
        }
    }
    fn diff(&self, word: &CountLetters) -> u32 {
        let mut resp = 0;
        for (letter, count) in &self.count {
            if let Some(countW) = word.count.get(letter) {
                if countW > count {
                    resp += countW - count;
                } else {
                    resp += count - countW;
                }
            } else {
                resp += count;
            }
        }
        for (letter, count) in &word.count {
            if self.count.get(letter).is_none() {
                resp += count;
            }
        }

        resp
    }
    fn diff_it(&self, word: &CountLetters) -> u32 {
        if self.word.len() != word.word.len() {
            10
        } else {
            let mut count = 0;
            for i in 0..self.word.len() {
                if self.word[i] != word.word[i] {
                    count += 1;
                }
            }
            count
        }
    }
}

struct MagicDictionary {
    words: Vec<CountLetters>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MagicDictionary {

    fn new() -> Self {
        Self {
            words: Default::default(),
        }
    }
    
    fn build_dict(&mut self, dictionary: Vec<String>) {
        for word in dictionary {
            self.words.push(CountLetters::new(word));
        }
    }
    
    fn search(&self, search_word: String) -> bool {
        let s_word = CountLetters::new(search_word);
        for word in &self.words {
            if word.diff(&s_word) == 2 && word.diff_it(&s_word) == 1 {
                return true;
            }
        }
        false
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * let obj = MagicDictionary::new();
 * obj.build_dict(dictionary);
 * let ret_2: bool = obj.search(searchWord);
 */
      
