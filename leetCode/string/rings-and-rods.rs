// https://leetcode.com/problems/rings-and-rods/
impl Solution {
    pub fn count_points(rings: String) -> i32 {
        let mut rods = [[false; 3]; 10];
        let len_rings = rings.len();
        let mut i = 0;
        let rings_chars = rings.chars().collect::<Vec<char>>();
        while i < len_rings {
            match rings_chars[i] {
                'R' => rods[rings_chars[i+1] as usize - '0' as usize][0] = true,
                'G' => rods[rings_chars[i+1] as usize - '0' as usize][1] = true,
                'B' => rods[rings_chars[i+1] as usize - '0' as usize][2] = true,
                _ => panic!("it should not happen"),
            }
            i += 2;
        }

        rods.iter().filter(|x| x[0] && x[1] && x[2]).count() as i32
    }
}
