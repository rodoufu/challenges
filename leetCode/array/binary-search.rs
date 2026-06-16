// https://leetcode.com/problems/binary-search/
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
       let mut low = 0;
       let mut high = nums.len() - 1;

       while low <= high && low >= 0 && high < nums.len() {
            let mid = low + (high - low) / 2;
            if nums[mid] == target {
                return mid as i32;
            }
            if nums[mid] < target {
                low = mid + 1;
            }
            if nums[mid] > target {
                high = mid - 1;
            }
       }
       return -1; 
    }
}
