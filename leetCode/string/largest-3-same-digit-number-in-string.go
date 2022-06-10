// https://leetcode.com/problems/largest-3-same-digit-number-in-string/
func largestGoodInteger(num string) string {
    resp := ""
    lenNum := len(num)
    for i := 2; i < lenNum; i++ {
        if num[i] == num[i - 1] && num[i] == num[i - 2] {
            if len(resp) == 0 || int(num[i]) > int(resp[0]) {
                resp = num[i-2:i+1]
            }
        }
    }
    return resp
}
