// https://leetcode.com/problems/triangle
impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut triangle = triangle;
        for i in (0..triangle.len()-1).rev() {
            for j in 0..triangle[i].len() {
                triangle[i][j] += i32::min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        triangle[0][0]
    }
}
