// https://leetcode.com/problems/valid-palindrome-ii/
func isPalindrome(s []byte) bool {
    fmt.Printf("Testing %v\n", string(s))
    lenS := len(s)
    for i := 0; i < lenS / 2; i++ {
        if s[i] != s[lenS - i - 1] {
            return false
        }
    }
    return true
}

func isPalindromeI(s string, b, e, count int) bool {
    if b >= e {
        return count <= 1
    }
    if count > 1 {
        return false
    }
    i := b
    j := e
    for  i < j {
        if s[i] != s[j] {
            return isPalindromeI(s, i, j - 1, count + 1) || isPalindromeI(s, i + 1, j, count + 1)
        }
        i++
        j--
    }
    return true
}

func validPalindrome(s string) bool {
    lenS := len(s)
    if lenS <= 2 {
        return true
    }
    
    return isPalindromeI(s, 0, lenS - 1, 0)
}
