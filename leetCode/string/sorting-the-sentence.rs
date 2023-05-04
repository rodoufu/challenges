// https://leetcode.com/problems/sorting-the-sentence
impl Solution {
    pub fn sort_sentence(s: String) -> String {
        let mut words: [&str; 9] = ["", "", "", "", "", "", "", "", ""];
        for x in s.split(' ') {
            let pos = x.chars().last().unwrap() as usize - '0' as usize -1;
            // println!("x:{}", pos);
            words[pos] = &x[..x.len()-1];
        }
        // println!("words: {words:?}");
        words.iter().filter(|x| !x.is_empty()).fold(String::new(), |a, b| a + " " + b).to_string().trim().to_string()
    }
}
