// https://leetcode.com/problems/flood-fill
use std::{
    cell::RefCell,
    rc::Rc,
};
impl Solution {
    fn fill(image: Rc<RefCell<Vec<Vec<i32>>>>, sr: i32, sc: i32, cur_color: i32) {
        if cur_color != image.borrow()[sr as usize][sc as usize] {
            return;
        }
        image.borrow_mut()[sr as usize][sc as usize] = -1;
        if sr - 1 >= 0 {
            Solution::fill(image.clone(), sr - 1, sc, cur_color);
        }
        if sc - 1 >= 0 {
            Solution::fill(image.clone(), sr, sc - 1, cur_color);
        }
        if (sr as usize + 1) < image.borrow().len() {
            Solution::fill(image.clone(), sr + 1, sc, cur_color);
        }
        if (sc as usize + 1) < image.borrow()[0].len() {
            Solution::fill(image.clone(), sr, sc + 1, cur_color);
        }
    }
    
    pub fn flood_fill(image: Vec<Vec<i32>>, sr: i32, sc: i32, color: i32) -> Vec<Vec<i32>> {
        let cur_color = image[sr as usize][sc as usize];
        let image = Rc::new(RefCell::new(image));
        Solution::fill(image.clone(), sr, sc, cur_color);

        let mut image = image.take();
        for row in &mut image {
            for x in row {
                if *x == -1 {
                    *x = color;
                }
            }
        }

        image
    }
}
