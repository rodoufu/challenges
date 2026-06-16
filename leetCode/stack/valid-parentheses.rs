// https://leetcode.com/problems/valid-parentheses/
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut processing = Vec::new();
        for c in s.chars() {
            match c {
                '(' | '[' | '{' => processing.push(c),
                ')' | ']' | '}' => {
                    let Some(top) = processing.pop() else {
                        return false;
                    };
                    match (top, c) {
                        ('(', ')') | ('[', ']') | ('{', '}') => {}
                        _ => return false,
                    }
                }
                _ => return false,
            }
        }

        processing.is_empty()
    }
}
