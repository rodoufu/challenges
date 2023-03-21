// https://leetcode.com/problems/find-median-from-data-stream
use std::collections::BTreeMap;
#[derive(Debug)]
struct MedianFinder {
    number_count: BTreeMap<i32, i32>,
    len: i32,
    median: Option<f64>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MedianFinder {

    fn new() -> Self {
        Self {
            number_count: Default::default(),
            len: 0,
            median: None,
        }
    }
    
    fn add_num(&mut self, num: i32) {
        *self.number_count.entry(num).or_default() += 1;
        self.len += 1;
        self.median = None;
    }
    
    fn find_median(&mut self) -> f64 {
        if let Some(median) = self.median {
            return median;
        }
        // println!("find_median {self:?}");
        if self.len % 2 != 0 {
            // println!("find_median odd");
            let mut idx = 0;
            for (num, count) in &self.number_count {
                // println!("num:{num}, count:{count}, idx:{idx}");
                idx += count;
                if idx >= (self.len / 2) + 1 {
                    self.median = Some(*num as f64);
                    return self.median.unwrap();
                }
            }
        } else {
            // println!("find_median even");
            let mut idx = 0;
            let mut first_num = None;
            for (num, count) in &self.number_count {
                // println!("num:{num}, count:{count}, idx:{idx}, first_num:{first_num:?}");
                if idx + count >= self.len / 2 && first_num.is_none(){
                    first_num = Some(num);
                }
                if idx + count >= (self.len / 2) + 1 {
                    if let Some(first_num) = first_num {
                        self.median = Some((first_num + num) as f64 / 2.0);
                        return self.median.unwrap();
                    } else {
                        self.median = Some(*num as f64);
                        return self.median.unwrap();
                    }
                }
                idx += count;
            }
        }

        std::f64::NAN
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder::new();
 * obj.add_num(num);
 * let ret_2: f64 = obj.find_median();
 */
