// https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value
func digitCount(num string) bool {
    var letterCount = map[int]int{
        0:0,
        1:0,
        2:0,
        3:0,
        4:0,
        5:0,
        6:0,
        7:0,
        8:0,
        9:0,
    }
    for _, letter := range num {
        letterInt, _ := strconv.Atoi(fmt.Sprintf("%c", letter))
        letterCount[letterInt]++
    }
    for i, count := range num {
        countInt, _ := strconv.Atoi(fmt.Sprintf("%c", count))
        if letterCount[i] != countInt {
            return false
        }
    }
    return true
}
