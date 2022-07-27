// https://leetcode.com/problems/delete-characters-to-make-fancy-string/
func makeFancyString(s string) string {
    var fancy strings.Builder
    previous := '1'
    count := 0
    
    for _, letter := range s {
        if letter != previous {
            fancy.WriteRune(letter)
            previous = letter
            count = 1
        } else if count < 2 {
            fancy.WriteRune(letter)
            count++
        }
    }
    
    return fancy.String()
}
