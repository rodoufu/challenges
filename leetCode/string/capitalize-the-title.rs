// https://leetcode.com/problems/capitalize-the-title/
impl Solution {
    pub fn capitalize_title(title: String) -> String {
        title.to_lowercase().split(" ").map(
            |x| if x.len() > 2 { 
                format!("{}{}", x[0..1].to_uppercase(), &x[1..]) 
            } else { 
                x.to_string() 
            }
        ).collect::<Vec<String>>().join(" ")
    }
}
