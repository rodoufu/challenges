package main
//https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/ON_OFF

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
    
    var numberOfButtons, changes int
    var buttonsBefore, buttonsAfter string
    for instance := 0; instance < instances; instance++ {
        _, err = fmt.Scanln(&numberOfButtons)
        if err != nil {
            os.Exit(1)
        }
        _, err = fmt.Scanln(&buttonsBefore)
        if err != nil {
            os.Exit(1)
        }
        _, err = fmt.Scanln(&buttonsAfter)
        if err != nil {
            os.Exit(1)
        }
        
        changes = 0
        for i := 0; i < numberOfButtons; i++ {
            if buttonsBefore[i] != buttonsAfter[i] {
                changes++
            }
        }
        
        if changes % 2 == 0 {
            fmt.Println("1")
        } else {
            fmt.Println("0")
        }
    }
}
