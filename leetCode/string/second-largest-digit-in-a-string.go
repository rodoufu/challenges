// https://leetcode.com/problems/second-largest-digit-in-a-string/
func secondHighest(s string) int {
    digits := map[int] struct {}{}
    for _, x := range s {
        //fmt.Printf("x: %v, %v, %v\n", int(x), int('0'), int('9'))
        if int('0') <= int(x) && int(x) <= int('9') {
            digits[int(x) - int('0')]=struct {}{}
        }
    }
    //fmt.Printf("d: %v\n", digits)
    if len(digits) < 2 {
        return -1
    }
    maxV := -1
    for x, _ := range digits {
        if x > maxV {
            maxV = x 
        }
    }
    maxz := -1
    for x, _ := range digits {
        if x != maxV && x > maxz {
            maxz = x 
        }
    }
    
    return maxz
}
