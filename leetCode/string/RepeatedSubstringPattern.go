func mdc(a, b int) int {
    for b != 0 {
        r := a % b
       a = b
       b = r 
    }
   return a
}

// https://leetcode.com/problems/repeated-substring-pattern/
func repeatedSubstringPattern(s string) bool {
    letters := make(map[rune]int)
    for _, x := range s {
        letters[x]++
    }
    if len(letters) == 1 && len(s) > 1 {
        //fmt.Printf("Aqui True 1\n")
        return true
    }
    minC := len(s)
    for _, c := range letters {
        if c < minC {
            minC = c
        }
    }
    //fmt.Printf("minC: %d\n", minC)
    for _, c := range letters {
        if mdc(c, minC) == 1 {
            //fmt.Printf("Aqui False 1\n")
            return false
        }
    }
    
    lenS := len(s)
    for i := 2; i <= lenS / 2; i++ {
        if lenS % i == 0 {
            if strings.Repeat(s[:i], lenS / i) == s {
                //fmt.Printf("Aqui True 2\n")
                return true
            }
        }
    }
    //fmt.Printf("Aqui False 2\n")
    return false
}
