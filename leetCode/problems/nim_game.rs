// https://leetcode.com/problems/nim-game/description/
impl Solution {
    pub fn can_win_nim(n: i32) -> bool {
        n % 4 != 0
    }
}
