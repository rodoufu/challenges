// https://leetcode.com/problems/sort-the-people
impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let mut names_heights = names.into_iter().zip(heights.into_iter()).collect::<Vec<(String, i32)>>();
        names_heights.sort_by(|a, b| b.1.cmp(&a.1));

        names_heights.into_iter().map(|(name, _)| name).collect()
    }
}
