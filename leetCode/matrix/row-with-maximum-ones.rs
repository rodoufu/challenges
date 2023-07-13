// https://leetcode.com/problems/row-with-maximum-ones/
impl Solution {
    pub fn row_and_maximum_ones(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut row = 0;
        let mut count = 0;
        for (idx, idx_count) in mat.into_iter().map(|x| x.into_iter().filter(|y| *y == 1).count()).enumerate() {
            if idx_count > count {
                count = idx_count;
                row = idx;
            }
        }

        vec![row as i32, count as i32]
    }
}
