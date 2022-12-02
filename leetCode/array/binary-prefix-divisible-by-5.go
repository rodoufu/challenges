// https://leetcode.com/problems/binary-prefix-divisible-by-5/
func prefixesDivBy5(nums []int) []bool {
    var resp []bool
    var cur uint64 = 0
    for _, x := range nums {
        cur = cur * 2 + uint64(x)
        resp = append(resp, cur % 5 == 0)
        cur = cur % 100
    }
    return resp
}
