// https://leetcode.com/problems/number-of-islands
impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut count_islands = 0;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == '1' {
                    count_islands += 1;
                    Self::expand_land(&mut grid, i, j);
                }
            }
        }

        count_islands
    }

    fn expand_land(grid: &mut Vec<Vec<char>>, x: usize, y: usize) {
        if x < 0 || y < 0 || x >= grid.len() || y >= grid[0].len() {
            return;
        }
        if grid[x][y] == '1' {
            grid[x][y] = '2';
            Self::expand_land(grid, x - 1, y);
            Self::expand_land(grid, x + 1, y);
            Self::expand_land(grid, x, y - 1);
            Self::expand_land(grid, x, y + 1);
        }
    }
}
