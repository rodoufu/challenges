//https://leetcode.com/problems/maximum-number-of-balloons
use std::collections::HashMap;

struct CountLetters {
    lc: HashMap<char, usize>,
}

impl CountLetters {
    fn new(t:&str) -> Self {
        let mut lc = HashMap::new();
        for c in t.chars() {
            *lc.entry(c).or_default() += 1;
        }

        Self {lc}
    }

    fn remove(&mut self, o:&Self)->bool {
        for (l,c) in &o.lc {
            let Some(mut sc) = self.lc.get_mut(&l) else {
                return false;
            };
            if *sc < *c {
                return false;
            }
            *sc -= *c;
        }
        true
    }
}

impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let mut r = 0;
        let mut a = CountLetters::new(&text);
        let b = CountLetters::new("balloon");
        while a.remove(&b) {
            r+=1;
        }
        r
    }
}
