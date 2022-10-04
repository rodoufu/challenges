// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
var numRunes = map[rune][]rune {
    '2': {'a', 'b', 'c'},
    '3': {'d', 'e', 'f'},
    '4': {'g', 'h', 'i'},
    '5': {'j', 'k', 'l'},
    '6': {'m', 'n', 'o'},
    '7': {'p', 'q', 'r', 's'},
    '8': {'t', 'u', 'v'},
    '9': {'w', 'x', 'y', 'z'},
}

func combinate(digits string, index int, found []string) []string {
    if index < 0 {
        return found
    }
    var resp[]string
    
    for _, letter := range numRunes[rune(digits[index])] {
        for _, word := range found {
            resp = append(resp, fmt.Sprintf("%c%v", letter, word))
        }
    }
    
    return combinate(digits, index - 1, resp)
}

func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return nil
    }
    return combinate(digits, len(digits) - 1, []string{""})
}
