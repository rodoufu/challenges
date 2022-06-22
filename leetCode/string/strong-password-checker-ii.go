// https://leetcode.com/problems/strong-password-checker-ii/
type charType int8

const (
    undefinedChartype charType = 0
    lowerCaseChartype charType = 1
    upperCaseChartype charType = 2
    digitChartype charType = 3
    specialCharChartype charType = 4
    
    specialChars = "!@#$%^&*()-+"
)

func getCharType(letter rune) charType {
    if unicode.IsDigit(letter) {
        return digitChartype
    }
    if unicode.IsLower(letter) {
        return lowerCaseChartype
    }
    if unicode.IsUpper(letter) {
        return upperCaseChartype
    }
    if strings.ContainsRune(specialChars, letter) {
        return specialCharChartype
    }
    return undefinedChartype
}

func strongPasswordCheckerII(password string) bool {
    if len(password) < 8 {
        return false
    }
    previous := rune(password[1])
    typeCount := map[charType]int{}
    for _, x := range password {
        if x == previous {
            return false
        }
        previous = x
        typeCount[getCharType(x)]++
    }
    
    if typeCount[lowerCaseChartype] == 0 {
        return false
    }
    if typeCount[upperCaseChartype] == 0 {
        return false
    }
    if typeCount[digitChartype] == 0 {
        return false
    }
    if typeCount[specialCharChartype] == 0 {
        return false
    }
    
    return true
}
