// https://leetcode.com/problems/number-of-senior-citizens/
impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        // 7868190130M7522
        details.iter().map(|x| x[11..13].parse::<i64>().unwrap()).filter(|x| *x > 60).count() as i32
    }
}
