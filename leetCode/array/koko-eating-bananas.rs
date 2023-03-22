// https://leetcode.com/problems/koko-eating-bananas/
use std::collections::HashMap;

impl Solution {
    fn number_of_hours(piles: &Vec<i32>, speed: i64) -> i64 {
        let mut hours: i64 = 0;
        for pile in piles {
            hours += (*pile as i64) / speed;
            if (*pile as i64) % speed != 0 {
                hours += 1;
            }
        }
        
        hours
    }

    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut low = 1;
        let mut high = *piles.iter().max().unwrap() as i64;
        let mut mid = (low + high) / 2;
        let mut mid_hours = Solution::number_of_hours(&piles, mid);
        let mut min_so_far = high;
        let h = h as i64;

        while low <= high {
            mid = (low + high) / 2;
            mid_hours = Solution::number_of_hours(&piles, mid);
            //println!("low:{low}, mid:{mid}, high:{high}, mid_hours:{mid_hours}, min_so_far:{min_so_far}");
            if mid_hours <= h && mid < min_so_far {
                min_so_far = mid;
            }
            if mid_hours == h {
                while mid_hours <= h {
                    if mid < min_so_far {
                        min_so_far = mid;
                    }
                    mid -= 1;
                    mid_hours = Solution::number_of_hours(&piles, mid);
                    //println!("-low:{low}, mid:{mid}, high:{high}, mid_hours:{mid_hours}, min_so_far:{min_so_far}");
                }
                break;
            } else if mid_hours > h {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        min_so_far as i32
    }
}
