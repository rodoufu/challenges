// https://leetcode.com/problems/sum-of-square-numbers/
func judgeSquareSum(c int) bool {
    if c == 0 {
        return true
    }
    to := int(math.Sqrt(float64(c))) + 1
    for i := 1; i < to; i++ {
        x := c - i * i
        sqx := int(math.Sqrt(float64(x)))
        if x == sqx * sqx {
            return true
        }
    }
    return false
}
