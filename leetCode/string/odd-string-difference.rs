// https://leetcode.com/problems/odd-string-difference

#[derive(Debug)]
struct Difference {
    sum: i32,
    difference: Vec<i32>,
}

impl PartialEq for Difference {
    fn eq(&self, other: &Self) -> bool {
        self.sum == other.sum && self.difference == other.difference
    }
}

impl Eq for Difference {}

impl From<&String> for Difference {
    fn from(word: &String) -> Self {
        let mut difference = Vec::new();
        let mut chars = word.chars().collect::<Vec<char>>();
        let len_c = chars.len();

        let mut sum = 0;
        for i in 0..len_c-1 {
            let temp = chars[i + 1] as i32 - chars[i] as i32;
            sum += temp;
            difference.push(temp);
        }

        Self {
            difference,
            sum,
        }
    }
}

impl Solution {
    pub fn odd_string(words: Vec<String>) -> String {
        let diffs = words.iter().map(Difference::from).collect::<Vec<Difference>>();
        if diffs[0] == diffs[1] {
            let len_w = diffs.len();
            for i in 2..len_w {
                if diffs[i] != diffs[0] {
                    return words[i].clone();
                }
            }

            "".to_string()
        } else if diffs[1] == diffs[2] {
            words[0].clone()
        } else {
            words[1].clone()
        }
    }
}
