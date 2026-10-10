package main
// https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/ALPHABET

import (
    "fmt"
    "os"
)

func main(){
	var alphabet string
	_, err := fmt.Scanln(&alphabet)
    if err != nil {
        os.Exit(1)
    }
    jeff := make(map[byte]struct{})
    for i := 0; i < len(alphabet); i++ {
        jeff[alphabet[i]] = struct{}{}
    }
    
	var instances int
    _, err = fmt.Scanln(&instances)
    if err != nil {
        os.Exit(1)
    }
    
    var word string
    var notInAlphabet bool
    for instance := 0; instance < instances; instance++ {
        notInAlphabet = false
    	_, err = fmt.Scanln(&word)
        if err != nil {
            os.Exit(1)
        }
        for i := 0; i < len(word); i++ {
            if _, ok := jeff[word[i]]; !ok {
                notInAlphabet = true
                break
            }
        }
        if notInAlphabet {
            fmt.Println("No")
        } else {
            fmt.Println("Yes")
        }
    }
}
