package main
// https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/TITLECASE

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "unicode"
)


func main(){
	var instances int
    _, err := fmt.Scanln(&instances)
    if err != nil {
        os.Exit(1)
    }
    
    var line string
    scanner := bufio.NewScanner(os.Stdin)
    for instance := 0; instance < instances; instance++ {
        for scanner.Scan() {
    		line = scanner.Text()
    		
    		break
    	}
    	
    	words := strings.Fields(line)
    	var builder strings.Builder
    	
    	for i := range words {
    	    if builder.Len() > 0 {
    	        builder.WriteByte(' ')
    	    }
    	    if strings.ToUpper(words[i]) == words[i] {
    	        builder.WriteString(words[i])
    	    } else {
    	        builder.WriteByte(byte(unicode.ToUpper(rune(words[i][0]))))
    	        builder.WriteString(strings.ToLower(words[i][1:]))
    	    }
    	}
    	
    	fmt.Println(builder.String())
    }
}
