// https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/WCC
package main

import (
    "fmt"
    "os"
)

func main() {
    var instances int
    _, err := fmt.Scanln(&instances)
    if err != nil {
        os.Exit(1)
    }
    
    var points, carlsen, chef, draw int
    var games string
    for instance := 0; instance < instances; instance++ {
        _, err = fmt.Scanln(&points)
        if err != nil {
            os.Exit(1)
        }
        _, err = fmt.Scanln(&games)
        if err != nil {
            os.Exit(1)
        }
        
        carlsen, chef, draw = 0, 0, 0
        for i := 0; i < len(games); i++ {
            switch games[i] {
                case 'C':
                    carlsen += 1
                case 'D':
                    draw += 1
                case 'N':
                    chef += 1
            }
        }
        
        carlsen = carlsen * 2 + draw
        chef = chef * 2 + draw
        
        if carlsen > chef {
            fmt.Printf("%v\n", 60 * points)
        } else if carlsen < chef {
            fmt.Printf("%v\n", 40 * points)
        } else {
            fmt.Printf("%v\n", 55 * points)
        }
    }
}
