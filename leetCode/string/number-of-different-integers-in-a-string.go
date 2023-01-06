// https://leetcode.com/problems/number-of-different-integers-in-a-string/
func numDifferentIntegers(word string) int {
    word = "a" + word +"a"
    nums := map[string] struct {}{}
    lw := len(word)
    for i:=1;i<lw;i++{
        if unicode.IsDigit(rune(word[i])) && !unicode.IsDigit(rune(word[i-1])) {
            j:=i 
            //val := 0
            for ; j<lw && unicode.IsDigit(rune(word [j])); j++{
               // val = 10*val+int(word[j])-int('0')
            }
            nums[strings.TrimLeft(word [i:j], "0")]=struct {}{} 
            //nums[val] =struct {}{}
        }
    } 
    //fmt.Printf("n: %v\n", nums)
                
    return len(nums)
}
