// https://leetcode.com/problems/compare-version-numbers/
use std::iter::*;

struct Revision {
    data: Vec<u32>,
}

impl From<&String> for Revision {
    fn from(version: &String) -> Self {
        let mut data = Vec::new();
        let mut current = 0;

        for a in version.chars() {
            if a == '.' {
                data.push(current);
                current = 0;
            } else {
                current = current * 10 + (a as u32 - '0' as u32);
            }
        }

        data.push(current);

        Self {
            data,
        }
    }
}

impl Revision {
    fn compare(&self, revision: &Revision) -> i32 {
        //println!("compare {:?}-{:?}", self.data, revision.data);

        let it: (Box<dyn Iterator<Item = &u32>>, Box<dyn Iterator<Item = &u32>>) = if self.data.len() < revision.data.len() {
            (
                Box::new(self.data.iter().chain(repeat(&0u32))),
                Box::new(revision.data.iter().chain(empty::<&u32>())),
            )
        } else {
            (
                Box::new(self.data.iter().chain(empty::<&u32>())),
                Box::new(revision.data.iter().chain(repeat(&0u32))),
            )
        };

        for (s, r) in it.0.zip(it.1) {
            //println!("s:{s}-r:{r}");
            if s < r {
                return -1;
            } else if s > r {
                return 1;
            }
        }

        0
    }
}

impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        Revision::from(&version1).compare(&Revision::from(&version2))
    }
}
