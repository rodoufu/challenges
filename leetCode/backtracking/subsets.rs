// https://leetcode.com/problems/subsets/
impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut resp = Default::default();
        let mut current = Default::default();

        //println!("nums: {nums:?}");
        Self::subset_gen(0, &nums, &mut current, &mut resp);
        resp
    }

    fn subset_gen(first: usize, nums: &Vec<i32>, current: &mut Vec<i32>, resp: &mut Vec<Vec<i32>>) {
        resp.push(current.clone());
        for i in first..nums.len() {
            //println!("i: {i}, nums[i]: {}, current: {current:?}", nums[i]);
            current.push(nums[i]);
            Self::subset_gen(i + 1, nums, current, resp);
            current.pop();
        }
    }
}
