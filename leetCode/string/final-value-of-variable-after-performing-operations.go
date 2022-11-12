// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
func finalValueAfterOperations(operations []string) int {
    resp := 0
    for _, op := range operations {
        if op[0] == '-' || op[2] == '-' {
            resp--
        } else {
            resp++
        }
    }
    return resp
}
