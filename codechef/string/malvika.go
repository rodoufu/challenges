// https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/CHN09
package main
import (
    "fmt"
    "os"
)

func main(){
    var err error
	var instances int
    _, err = fmt.Scanln(&instances)
    if err != nil {
        os.Exit(1)
    }
    
    var ballons string
    var amber, brass int
    for instance := 0; instance < instances; instance++ {
        _, err = fmt.Scanln(&ballons)
        if err != nil {
            os.Exit(1)
        }
        
        amber, brass = 0, 0
        for i := 0; i < len(ballons); i++ {
            if ballons[i] == 'a' {
                amber += 1
            } else if ballons[i] == 'b' {
                brass += 1
            }
        }
        
        if amber < brass {
            fmt.Printf("%v\n", amber)
        } else {
            fmt.Printf("%v\n", brass)
        }
    }
}
