// https://leetcode.com/problems/design-add-and-search-words-data-structure
use std::collections::HashMap;
use std::rc::Rc;
use std::cell::RefCell;
use std::str::Chars;

#[derive(Debug, Clone, Default)]
struct WordDictionary {
    next_nodes: HashMap<char, Rc<RefCell<WordDictionary>>>,
    ends_here: bool,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl WordDictionary {
    fn new() -> Self {
        Self::default()
    }
    
    fn add_word(&mut self, word: String) {
        self.add_word_chars(word.chars());
    }

    fn add_word_chars(&mut self, mut word: Chars<'_>) {
        let Some(first) = word.next() else {
            self.ends_here = true;
            return;
        };
        let trie_next = self.next_nodes.entry(first).or_default();
        trie_next.borrow_mut().add_word_chars(word);
    }
    
    fn search(&self, word: String) -> bool {
        self.search_chars(word.chars())
    }

    fn search_chars(&self, mut word: Chars<'_>) -> bool {
        //println!("word: {}, is_prefix: {is_prefix}", word.clone().collect::<String>());
        let Some(first) = word.next() else {
            return self.ends_here;
        };
        if first != '.' {
            let Some(trie_next) = self.next_nodes.get(&first) else {
                return false;
            };
            return trie_next.borrow().search_chars(word);
        }

        for next_node in self.next_nodes.values() {
            if next_node.borrow().search_chars(word.clone()) {
                return true;
            }
        }

        false
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * let obj = WordDictionary::new();
 * obj.add_word(word);
 * let ret_2: bool = obj.search(word);
 */
