// Padovan sequence
package main

import (
    "fmt"
)

func Padovan(p *[]int, n int) int {
	if n + 1 < len(*p) {
		return (*p)[n]
	}
	for i := len(*p); i <= n; i++ {
		*p = append(*p, (*p)[i - 1] + (*p)[i - 5])
	}
	return (*p)[n]
}

func main() {
	// 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37
	//          1  5  5  5  5  5  5  5   5   5   5    5
	// 1  2  3  4  5  6  7  8  9 10  11  12  13  14  15
	padovanMem := []int{0, 1, 1, 1, 2, 2}
	var i int
	var err error
	_, err = fmt.Scanf("%d", &i)
	for err == nil {
		fmt.Printf("%d\n", Padovan(&padovanMem, i))
		_, err = fmt.Scanf("%d", &i)
	}
	
}
