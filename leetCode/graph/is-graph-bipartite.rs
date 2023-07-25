// https://leetcode.com/problems/is-graph-bipartite
use std::collections::{
    HashMap,
    HashSet,
};

impl Solution {
    pub fn is_bipartite(graph: Vec<Vec<i32>>) -> bool {
        let mut nodes_a = HashSet::<i32>::new();
        let mut nodes_b = HashSet::<i32>::new();
        
        let len_g = graph.len() as i32;
        let mut next_node = vec![0];
        let mut not_visited: HashSet<i32> = (1..len_g).collect();
        let mut visited: HashSet<i32> = HashSet::new();

        loop {
            if next_node.is_empty() && not_visited.is_empty() {
                break;
            }
            if next_node.is_empty() {
                let x = not_visited.iter().copied().next().unwrap();
                not_visited.remove(&x);
                next_node.push(x);
            }

            let x = next_node.pop().unwrap();
            visited.insert(x);
            not_visited.remove(&x);
            // println!("x:{x}");

            match (nodes_a.contains(&x), nodes_b.contains(&x)) {
                (true, true) => {
                    // println!("oi 1");
                    return false
                },
                (true, false) => {
                    for y in &graph[x as usize] {
                        if nodes_a.contains(y) {
                            // println!("oi 2");
                            return false;
                        }
                        nodes_b.insert(*y);
                        if !visited.contains(y) {
                            next_node.push(*y);
                        }
                    }
                },
                (false, true) => {
                    for y in &graph[x as usize] {
                        if nodes_b.contains(y) {
                            // println!("oi 3 x:{x}, y:{y} nodes_a:{nodes_a:?}, nodes_b:{nodes_b:?}");
                            return false;
                        }
                        nodes_a.insert(*y);
                        if !visited.contains(y) {
                            next_node.push(*y);
                        }
                    }
                },
                (false, false) => {
                    let adjacent_group = graph[x as usize].iter().filter_map(|x| if nodes_a.contains(x) { Some('a') } else { None }).chain(
                        graph[x as usize].iter().filter_map(|x| if nodes_b.contains(x) { Some('b') } else { None })
                    ).collect::<HashSet<_>>();
                    if adjacent_group.len() > 1 {
                        // println!("oi  x:{x}, nodes_a:{nodes_a:?}, nodes_b:{nodes_b:?}");
                        return false;
                    }

                    if adjacent_group.contains(&'a') {
                        nodes_b.insert(x);
                        for y in &graph[x as usize] {
                            if nodes_b.contains(y) {
                                // println!("oi 5");
                                return false;
                            }
                            nodes_a.insert(*y);
                            if !visited.contains(y) {
                                next_node.push(*y);
                            }
                        }
                    } else if adjacent_group.contains(&'b') {
                        nodes_a.insert(x);
                        for y in &graph[x as usize] {
                            if nodes_a.contains(y) {
                                // println!("oi 6");
                                return false;
                            }
                            nodes_b.insert(*y);
                            if !visited.contains(y) {
                                next_node.push(*y);
                            }
                        }
                    } else {
                        nodes_a.insert(x);
                        for y in &graph[x as usize] {
                            if nodes_a.contains(y) {
                                // println!("oi 7");
                                return false;
                            }
                            nodes_b.insert(*y);
                            if !visited.contains(y) {
                                next_node.push(*y);
                            }
                        }
                    }
                },
            }
        }

        true     
    }
}
