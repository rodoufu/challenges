// https://leetcode.com/problems/combination-sum/
use std::collections::HashSet;

impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut resp: HashSet<Vec<i32>> = HashSet::new();

        for candidate in &candidates {
            if *candidate == target{
                resp.insert(vec![*candidate]);
                break;
            }
        }

        let mut pilha = vec![(Vec::new(), 0)];
        while !pilha.is_empty() {
            if resp.len() == 150 {
                break;
            }
            
            let (it, sum) = pilha.pop().unwrap();

            for candidate in &candidates {
                if sum + *candidate < target {
                    let mut new_it = it.clone();
                    new_it.push(*candidate);

                    pilha.push((new_it, sum + *candidate));
                } else if sum + *candidate == target {
                    let mut new_it = it.clone();
                    new_it.push(*candidate);
                    new_it.sort();

                    resp.insert(new_it);
                }
            }
        }

        resp.into_iter().collect()
    }
}
