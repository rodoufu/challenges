package main
// https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/DDMMORMMDD

import (
    "fmt"
    "os"
)

func main() {
    var instances, first, second, year int
    _, err := fmt.Scanln(&instances)
    if err != nil {
        os.Exit(1)
    }
    
    for instance := 0; instance < instances; instance++ {
        _, err := fmt.Scanf("%d/%d/%d", &first, &second, &year)
        if err != nil {
            os.Exit(1)
        }
        
        if first <= 12 && second <= 12 {
            fmt.Println("BOTH")
        } else if first <= 12 {
            fmt.Println("MM/DD/YYYY")
        } else {
            fmt.Println("DD/MM/YYYY")
        }
    }
}
