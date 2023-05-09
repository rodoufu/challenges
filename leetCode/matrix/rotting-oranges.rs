// https://leetcode.com/problems/rotting-oranges
use std::mem;
impl Solution {
    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let mut count = -1;

        let n = grid.len();
        let m = grid[0].len();

        let mut temp_line = Vec::new();
        temp_line.resize(m, 0);
        let mut temp_grid = Vec::new();
        temp_grid.resize(n, temp_line);

        let mut has_rottenend = true;
        let mut has_fresh = false;
        while has_rottenend {
            has_rottenend = false;
            has_fresh = false;
            for i in 0..n {
                for j in 0..m {
                    temp_grid[i][j] = grid[i][j];
                }
            }

            for i in 0..n {
                for j in 0..m {
                    if grid[i][j] == 2 {
                        if i >= 1 && grid[i - 1][j] == 1 {
                            // println!("i:{i}, j:{j} oi 1");
                            temp_grid[i - 1][j] = 2;
                            has_rottenend = true;
                        }
                        if j >= 1 && grid[i][j - 1] == 1 {
                            // println!("i:{i}, j:{j} oi 2");
                            temp_grid[i][j - 1] = 2;
                            has_rottenend = true;
                        }

                        if i + 1 < n && grid[i + 1][j] == 1 {
                            // println!("i:{i}, j:{j} oi 3");
                            temp_grid[i + 1][j] = 2;
                            has_rottenend = true;
                        }
                        if j + 1 < m && grid[i][j + 1] == 1 {
                            // println!("i:{i}, j:{j} oi 4");
                            temp_grid[i][j + 1] = 2;
                            has_rottenend = true;
                        }
                    } else if grid[i][j] == 1 {
                        has_fresh = true;
                    }
                }
            }
            mem::swap(&mut grid, &mut temp_grid);
            count += 1;
            // println!("count:{count}, rotten:{has_rottenend}, fresh:{has_fresh}, grid:{grid:?}, temp_grid:{temp_grid:?}");
        }

        if has_fresh {
            -1
        } else {
            count
        }
    }
}
