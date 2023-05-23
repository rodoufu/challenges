// https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/
use std::{
    collections::HashSet,
    iter::FromIterator,
};
impl Solution {
    pub fn min_number(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let nums1 = HashSet::<i32>::from_iter(nums1.into_iter());
        let nums2 = HashSet::<i32>::from_iter(nums2.into_iter());

        for x in 1..10 {
            if nums1.contains(&x) && nums2.contains(&x) {
                return x;
            }
        }
        let smallest1 = nums1.iter().copied().min().unwrap();
        let smallest2 = nums2.iter().copied().min().unwrap();
        if smallest1 < smallest2 {
            return 10 * smallest1 + smallest2;
        }

        10 * smallest2 + smallest1
    }
}
