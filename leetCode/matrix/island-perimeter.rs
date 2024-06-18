// https://leetcode.com/problems/island-perimeter
impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let mut perimeter = 0;
        let len_g = grid.len();
        let len_g0 = grid[0].len();

        for i in 0..len_g {
            for j in 0..len_g0 {
                if grid[i][j] == 0 {
                    continue;
                }
                perimeter += 4;
                if i > 0 && grid[i - 1][j] == 1 {
                    perimeter -= 1;
                }
                if j > 0 && grid[i][j - 1] == 1 {
                    perimeter -= 1;
                }
                if i + 1 < len_g && grid[i + 1][j] == 1 {
                    perimeter -= 1;
                }
                if j + 1 < len_g0 && grid[i][j + 1] == 1 {
                    perimeter -= 1;
                }
            }
        }

        perimeter
    }
}
