// https://leetcode.com/problems/01-matrix
use std::{
    cell::RefCell,
    rc::Rc,
};

impl Solution {
    fn update_pos(pos: [usize; 2], mat: Rc<RefCell<Vec<Vec<i32>>>>, n: usize, m: usize) {
        let mut neighbors: Vec<[usize; 2]> = Vec::new();
        if pos[0] >= 1 {
            neighbors.push([pos[0] - 1, pos[1]]);
        }
        if pos[1] >= 1 {
            neighbors.push([pos[0], pos[1] - 1]);
        }
        if pos[0] + 1 < n {
            neighbors.push([pos[0] + 1, pos[1]]);
        }
        if pos[1] + 1 < m {
            neighbors.push([pos[0], pos[1] + 1]);
        }

        // println!("pos:{pos:?}, neighbors:{neighbors:?}, n:{n}, m:{m}");
        let mut val = mat.borrow()[pos[0]][pos[1]];
    
        for neighbor in &neighbors {
            let neighbor_val = mat.borrow()[neighbor[0]][neighbor[1]];
            if neighbor_val + 1 < val {
                mat.borrow_mut()[pos[0]][pos[1]] = neighbor_val + 1;
                val = neighbor_val + 1;
            }
        }

        for neighbor in neighbors {
            let neighbor_val = mat.borrow()[neighbor[0]][neighbor[1]];
            if val + 1 < neighbor_val {
                Solution::update_pos(neighbor, mat.clone(), n, m);
            }
        }
    }

    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = mat.len();
        if n == 0 {
            return Vec::new();
        }

        let m = mat[0].len();
        if m == 0 {
            return vec![Vec::new()];
        }

        let mut temp = Vec::new();
        temp.resize(m, (n + m) as i32);
        let mut resp = Vec::new();
        resp.resize(n, temp);

        for i in 0..n {
            for j in 0..m {
                if mat[i][j] == 0 {
                    resp[i][j] = 0;
                }
            }
        }

        let resp = Rc::new(RefCell::new(resp));
        for i in 0..n {
            for j in 0..m {
                Solution::update_pos([i, j], resp.clone(), n, m);
            }
        }


        // println!("resp: {resp:?}");
        let resp = resp.borrow().clone();
        resp
    }
}
