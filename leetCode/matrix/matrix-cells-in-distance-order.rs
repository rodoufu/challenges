// https://leetcode.com/problems/matrix-cells-in-distance-order/
impl Solution {
    fn matrix_distance(r1: i32, c1: i32, r2: i32, c2: i32) -> i32 {
        i32::abs(r1 - r2) + i32::abs(c1 - c2)
    }
    pub fn all_cells_dist_order(rows: i32, cols: i32, r_center: i32, c_center: i32) -> Vec<Vec<i32>> {
        let mut resp: Vec<Vec<i32>> = Vec::new();
        //println!("r_center: {}, c_center: {}", r_center, c_center);
        for row in 0..rows {
            for col in 0..cols {
                let rc_dist = Solution::matrix_distance(r_center, c_center, row, col);

                let mut i = resp.len();
                //println!("row: {}, col: {}, rc_dist: {}, resp: {:?}", row, col, rc_dist, resp);
                while i >= 0 {
                    if i == 0 {
                        //println!("i: {}, added: {:?}", i, vec![row, col]);
                        resp.insert(i, vec![row, col]);
                        break;
                    }
                    let cur_dist = Solution::matrix_distance(r_center, c_center, resp[i - 1][0], resp[i - 1][1]);
                    //println!("i: {}, cur_dist: {}", i, cur_dist);
                    if cur_dist <= rc_dist || i == 0 {
                        //println!("i: {}, added: {:?}", i, vec![row, col]);
                        resp.insert(i, vec![row, col]);
                        break;
                    }
                    i -= 1;
                }
            }
        }
        
        return resp;
    }
}
