// https://leetcode.com/problems/calculate-digit-sum-of-a-string/
func digitSum(s string, k int) string {
    var sb strings.Builder
    
    lenS := len(s)
    if lenS <= k {
        return s
    }
    for i := 0; i < lenS; i += k {
        right := i + k
        if right > lenS {
            right = lenS
        }
        
        toSum := s[i:right]
        value := 0
        for _, x := range toSum {
            value += int(x) - int('0')
        }
        //fmt.Printf("toSum: %v, value: %v\n", toSum, value)
        sb.WriteString(fmt.Sprintf("%v", value))
    }
    
    resp := sb.String()
    if len(resp) <= k {
        return resp
    }
    return digitSum(resp, k)
}
