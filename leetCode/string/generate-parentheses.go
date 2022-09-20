// https://leetcode.com/problems/generate-parentheses/
func generateParenthesis(n int) []string {
    valids := map[int]map[string]struct{}{
        0: {
            "": {},
        },
    }
    
    for i := 1; i <= n; i++ {
        //fmt.Printf("valids: %v\n", valids)
        valids[i] = map[string]struct{}{}
        for value, _ := range valids[i - 1] {
            valids[i][fmt.Sprintf("(%v)", value)] = struct{}{}
            valids[i][fmt.Sprintf("%v()", value)] = struct{}{}
            valids[i][fmt.Sprintf("()%v", value)] = struct{}{}
        }
        for j := 1; j < i; j++ {
            for valueJ, _ := range valids[j] {
                if i - j > 0 {
                    for valueK, _ := range valids[i - j] {
                        valids[i][fmt.Sprintf("%v%v", valueJ, valueK)] = struct{}{}
                        valids[i][fmt.Sprintf("%v%v", valueK, valueJ)] = struct{}{}
                    }
                }
            }
        }
    }
    
    resp := make([]string, 0, len(valids))
    for value, _ := range valids[n] {
        resp = append(resp, value)
    }
    return resp
}
