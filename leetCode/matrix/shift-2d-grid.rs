/// https://leetcode.com/problems/shift-2d-grid/
impl Solution {
    #[inline]
    fn get_x_y(n: usize, pos: usize) -> (usize, usize) {
        (pos / n, pos % n)
    }

    pub fn shift_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let n = grid[0].len();
        let m = grid.len();
        let k =  (k as usize) %(n*m);
        let k = (n * m) - k;
        
        if k == 0 {
            return grid;
        }

        let mut resp = Vec::new();
        let mut pos = 0;
        for i in 0..m {
            resp.push(Vec::new());
            for j in 0..n {
                let (x, y) = Self::get_x_y(n, (pos + k) % (n*m));
                // println!("pos: {pos}, k: {k}, x: {x}, y: {y}, n: {n}, m: {m}");
                resp[i].push(grid[x][y]);
                pos += 1;
            }
        }

        resp
    }
}
