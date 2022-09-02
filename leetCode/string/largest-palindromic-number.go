// https://leetcode.com/problems/largest-palindromic-number/
func largestPalindromic(num string) string {
    letterCount := make(map[rune]int)
    
    for _, letter := range num {
        letterCount[letter]++
    }
    
    var resp strings.Builder
    var toAdd []rune
    middle := ""
    
    for j := 9; j >= 0; j-- {
        letter := rune('0' + j)
        count, ok := letterCount[letter]
        if !ok {
            continue
        }
        if j == 0 && len(toAdd) == 0 {
            if len(middle) == 0 {
                return "0"
            }
            continue
        }
        if count % 2 == 1 && len(middle) == 0 {
            middle = string(letter)
        }
        for i := 0; i < count / 2; i++ {
            toAdd = append(toAdd, letter)
            resp.WriteRune(letter)
        }
    }
    
    resp.WriteString(middle)
    
    lenAdd := len(toAdd)
    for i := lenAdd - 1; i >= 0; i-- {
        resp.WriteRune(toAdd[i])
    }
    return resp.String()
}
