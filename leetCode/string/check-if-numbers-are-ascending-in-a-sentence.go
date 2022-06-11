// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
func areNumbersAscending(s string) bool {
    words := strings.Split(s, " ")
    var previousNumber int
    firstNumber := true
    for _, w := range words {
        intVal, err := strconv.Atoi(w)
        if err == nil {
            //fmt.Printf("num: %v\n", intVal)
            if firstNumber {
                previousNumber = intVal
                firstNumber = false
                continue
            }
            if intVal <= previousNumber {
                return false
            }
            previousNumber = intVal
        }
    }
    return true
}
