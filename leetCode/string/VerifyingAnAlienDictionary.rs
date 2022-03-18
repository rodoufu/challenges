// https://leetcode.com/problems/verifying-an-alien-dictionary/
use std::collections::HashMap;

impl Solution {
    fn cmp_str(word1: &String, word2: &String, alpha_order: &HashMap<char, usize>) -> bool {
        let mut len_word = word1.len();
        if len_word > word2.len() {
            len_word = word2.len();
        }
        let word1_c: Vec<char> = word1.chars().collect();
        let word2_c: Vec<char> = word2.chars().collect();
        for i in 0..len_word {
            let vw1 = alpha_order[&word1_c[i]];
            let vw2 = alpha_order[&word2_c[i]];
            /*println!(
                "v({})>v({}) ? {}>{}",
                word1_c[i], word2_c[i],
                vw1, vw2
            );*/
            if vw1 == vw2 {
                continue;
            }
            return vw1 < vw2;
        }
        if word1.len() != word2.len() {
            return word1.len() < word2.len();
        }
        true
    }
    
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mut alpha_order = HashMap::new();
        let order_c: Vec<char> = order.chars().collect();
        for i in 0..order.len() {
            alpha_order.insert(order_c[i], i);
        }
        //println!("alpha_order: {:?}", alpha_order);
        
        for i in 1..words.len() {
            if !Solution::cmp_str(&words[i - 1], &words[i], &alpha_order) {
                return false;
            }
        }
        
        true
    }
}
