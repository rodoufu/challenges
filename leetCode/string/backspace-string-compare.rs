// https://leetcode.com/problems/backspace-string-compare/
impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let mut s_list = Vec::new();
        for it in s.chars() {
            if it == '#' {
                s_list.pop();
            } else {
                s_list.push(it);
            }
        }
        
        let mut t_list = Vec::new();
        for it in t.chars() {
            if it == '#' {
                t_list.pop();
            } else {
                t_list.push(it);
            }
        }
        if s_list.len() != t_list.len() {
            return false;
        }
        for i in 0..(s_list.len()) {
            if s_list[i] != t_list[i] {
                return false
            }
        }
        true
    }
}
