package main
// https://www.codechef.com/practice/course/strings-new/STRINGSP01/problems/LARGODDSTRIN
import (
    "fmt"
    "os"
)

func main(){
	var nums string
    _, err := fmt.Scanln(&nums)
    if err != nil {
        os.Exit(1)
    }
    
    for i := 0; i < len(nums); i++ {
        if (nums[len(nums) - i - 1] - '0') & 1 == 1 {
            fmt.Printf("%v\n", nums[0:len(nums) - i])
            return
        }
    }
    fmt.Println("-1")
}
