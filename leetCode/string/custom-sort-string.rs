// https://leetcode.com/problems/custom-sort-string/
use std::collections::HashMap;
use std::char;

impl Solution {
    pub fn custom_sort_string(order: String, s: String) -> String {
        let mut letter_cost = HashMap::new();
        for (i, x) in order.chars().enumerate() {
            letter_cost.insert(x, i);
        }

        let mut letters_s = s.chars().collect::<Vec<char>>(); 
        println!("letter_cost: {letter_cost:?}, order: {order}, s: {s}");
        letters_s.sort_by(|a, b| letter_cost.get(&a).unwrap_or(&0usize).partial_cmp(letter_cost.get(&b).unwrap_or(&0usize)).unwrap());

        letters_s.iter().map(char::to_string).collect::<Vec<String>>().join("")
    }
}
