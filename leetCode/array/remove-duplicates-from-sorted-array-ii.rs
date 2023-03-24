// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
use std::mem;
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() < 2 {
            return nums.len() as i32;
        }
        let mut last = 2;
        let nums_len = nums.len();
        let mut point = last;
        while point < nums_len {
            //println!("point:{point}, last:{last}, nums:{nums:?}");
            if nums[point] == nums[last - 2] {
                point += 1;
            } else {
                let temp = nums[point];
                nums[point] = nums[last];
                nums[last] = temp;

                point += 1;
                last += 1;
            }
        }
        //println!("point:{point}, last:{last}, nums:{nums:?}");
        last as i32
    }
}
