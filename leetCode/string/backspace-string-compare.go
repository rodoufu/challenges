// https://leetcode.com/problems/backspace-string-compare/
func backspaceCompare(s string, t string) bool {
    indexS := len(s) - 1
    indexT := len(t) - 1
    backspaceS := 0
    backspaceT := 0
    
    for indexS >= 0 && indexT >= 0 {
        if s[indexS] == '#' {
            backspaceS++
            indexS--
            continue
        }
        if t[indexT] == '#' {
            backspaceT++
            indexT--
            continue
        }
        if backspaceS > 0 {
            backspaceS--
            indexS--
            continue
        }
        if backspaceT > 0 {
            backspaceT--
            indexT--
            continue
        }
        if s[indexS] != t[indexT] {
            //fmt.Printf("s: %v, t: %v\n", s[indexS], t[indexT])
            return false
        }
        indexS--
        indexT--
    }
    
    for indexS >= 0 {
        if s[indexS] == '#' {
            backspaceS++
            indexS--
            continue
        }
        if backspaceS > 0 {
            backspaceS--
            indexS--
            continue
        }
        return false
    }
    
    for indexT >= 0 {
        if t[indexT] == '#' {
            backspaceT++
            indexT--
            continue
        }
        if backspaceT > 0 {
            backspaceT--
            indexT--
            continue
        }
        return false
    }
    
    //fmt.Printf("indexS: %v, indexT: %v\n", indexS, indexT)
    return indexS == indexT
}
