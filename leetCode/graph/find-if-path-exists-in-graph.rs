// https://leetcode.com/problems/find-if-path-exists-in-graph/
use std::collections::{
    HashMap,
    HashSet,
};

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let mut graph: HashMap<i32, HashSet<i32>> = HashMap::new();
        for edge in edges {
            graph.entry(edge[0]).or_default().insert(edge[1]);
            graph.entry(edge[1]).or_default().insert(edge[0]);
        }

        let mut visited = HashSet::from([source]);
        let mut to_visit = vec![source];

        while !to_visit.is_empty() {
            let node = to_visit.pop().unwrap();
            if node == destination {
                return true;
            }

            if let Some(neighbors) = graph.get(&node) {
                for neighbor in neighbors {
                    if !visited.contains(neighbor) {
                        visited.insert(*neighbor);
                        to_visit.push(*neighbor);
                    }
                }
            }
        }

        false
    }
}
