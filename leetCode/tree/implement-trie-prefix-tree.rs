// https://leetcode.com/problems/implement-trie-prefix-tree/
use std::collections::HashMap;
use std::rc::Rc;
use std::cell::RefCell;
use std::str::Chars;

#[derive(Debug, Clone, Default)]
struct Trie {
    next_nodes: HashMap<char, Rc<RefCell<Trie>>>,
    ends_here: bool,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {
    fn new() -> Self {
        Default::default()
    }
    
    fn insert(&mut self, word: String) {
        self.insert_chars(word.chars());
        //println!("trie: {self:?}");
    }

    fn insert_chars(&mut self, mut word: Chars<'_>) {
        let Some(first) = word.next() else {
            self.ends_here = true;
            return;
        };
        let trie_next = self.next_nodes.entry(first).or_default();
        trie_next.borrow_mut().insert_chars(word);
    }
    
    fn search(&self, word: String) -> bool {
        self.search_chars(word.chars(), false)
    }

    fn search_chars(&self, mut word: Chars<'_>, is_prefix: bool) -> bool {
        //println!("word: {}, is_prefix: {is_prefix}", word.clone().collect::<String>());
        let Some(first) = word.next() else {
            return is_prefix || self.ends_here;
        };
        let Some(trie_next) = self.next_nodes.get(&first) else {
            return false;
        };
        trie_next.borrow().search_chars(word, is_prefix)
    }
    
    fn starts_with(&self, prefix: String) -> bool {
        self.search_chars(prefix.chars(), true)
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie::new();
 * obj.insert(word);
 * let ret_2: bool = obj.search(word);
 * let ret_3: bool = obj.starts_with(prefix);
 */
