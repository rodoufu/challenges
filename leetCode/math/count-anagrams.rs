// https://leetcode.com/problems/count-anagrams
use std::{
    collections::{
        BTreeMap,
        HashMap,
    },
    iter,
    ops::{
        Div,
        Mul,
    },
};

const Fix: usize = 1_000_000_000 + 7;

#[derive(Debug)]
struct CountLetters {
    data: HashMap<char, usize>,
    len: usize,
}

impl From<&str> for CountLetters {
    fn from(word: &str) -> Self {
        let mut data = HashMap::new();
        for letter in word.chars() {
            *data.entry(letter).or_default() += 1;
        }
        Self {
            data,
            len: word.len(),
        }
    }
}

#[derive(Default, Debug)]
struct Product {
    num_count: HashMap<u64, i32>,
}

impl From<CountLetters> for Product {
    fn from(count_letter: CountLetters) -> Self {
        if count_letter.data.len() == 1 {
            return Self::default();
        }
        let mut resp = Product::default();
        //println!("count_letter:{count_letter:?}");
        for x in 2..count_letter.len+1 {
            resp.add_mul_div(x as u64, 1);
        }
        for (_, count) in &count_letter.data {
            for x in 2..count+1 {
                resp.add_mul_div(x as u64, -1);
            }
        }
        //println!("from:{resp:?}");
        resp
    }
}

impl Mul for Product {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        //println!("{self:?}*{rhs:?}");
        let mut num_count = self.num_count;

        for (num, count) in rhs.num_count {
            let mut x = num_count.entry(num).or_default();
            *x += count;
            if *x == 0 {
                num_count.remove(&(num as u64));
            }
        }

        //println!("=={num_count:?}");
        Self {
            num_count,
        }
    }
}

impl Product {
    fn add_mul_div(&mut self, val: u64, is_mul: i32) {
        let mut val = val;
        while val % 2 == 0 {
            *self.num_count.entry(2).or_default() += is_mul;
            val /= 2;
        }
        if let Some(x) = self.num_count.get(&2) {
            if *x == 0 {
                self.num_count.remove(&2);
            }
        }
        if val == 1 {
            return;
        }

        let mut x = 3;
        let x_end = (val as f64).sqrt() as u64 + 1;
        while x < x_end {
            if val % x == 0 {
                let mut y = self.num_count.entry(x).or_default();
                *y += is_mul;
                if *y == 0 {
                    self.num_count.remove(&x);
                }
                self.add_mul_div(val / x, is_mul);
                return;
            }
            x += 2;
        }

        let mut y = self.num_count.entry(val).or_default();
        *y += is_mul;
        if *y == 0 {
            self.num_count.remove(&val);
        }
    }

    fn calculate(self) -> i32 {
        let mut resp = 1usize;
        for (num, count) in self.num_count {
            if count > 0 {
                for _ in 0..count {
                    resp = (resp * num as usize) % Fix;
                }
            } else {
                for _ in 0..-count {
                    resp = (resp / num as usize) % Fix;
                }
            }
        }

        resp as i32
    }
}

impl Solution {
    pub fn count_anagrams(s: String) -> i32 {
        s.split(" ")
            .map(CountLetters::from)
            .map(Product::from)
            .fold(
                Product{num_count: HashMap::new()}, 
                |prod, val| prod * val
            )
            .calculate()
    }
}
