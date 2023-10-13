// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
impl Solution {
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        if arr.len() < 2 {
            return false;
        }
        
        let mut arr = arr;
        arr.sort();
        let diff = arr[1] - arr[0];

        for i in 2..arr.len() {
            if arr[i] - arr[i - 1] != diff {
                return false;
            }
        }

        true
    }
}
