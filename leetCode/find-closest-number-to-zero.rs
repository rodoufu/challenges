// https://leetcode.com/problems/find-closest-number-to-zero/
impl Solution {
    pub fn find_closest_number(nums: Vec<i32>) -> i32 {
        let mut closest = nums[0];
        for x in nums {
            let x_abs = i32::abs(x);
            let c_abs = i32::abs(closest);
            if x_abs < c_abs || (x_abs == c_abs && x > closest) {
                closest = x;
            }
        }
        closest
    }
}
