// https://leetcode.com/problems/add-binary/
use std::{
    iter,
    usize,
};

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut resp = String::from("");
        let map_f = |x| if x == '0' { 0 } else { 1 };
        let to_iterate = if a.len() > b.len() {
            a.chars().rev().map(map_f).zip(
                b.chars().rev().map(map_f).chain(iter::repeat(0))
            )
        } else {
            b.chars().rev().map(map_f).zip(
                a.chars().rev().map(map_f).chain(iter::repeat(0))
            )
        };
        
        let mut vai_um = 0;
        for (ai, bi) in to_iterate {
            match vai_um + ai + bi {
                0 => {
                    resp.push('0');
                }
                1 => {
                    resp.push('1');
                    vai_um = 0;
                }
                2 => {
                    resp.push('0');
                    vai_um = 1;
                }
                3 => {
                    resp.push('1');
                    vai_um = 1;
                }
                _ => {
                    panic!("unexpected value")
                }
            }
        }
        if vai_um == 1 {
            resp.push('1');
        }
        
        resp.chars().rev().collect::<String>()
    }
}
