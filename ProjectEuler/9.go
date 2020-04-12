package main

import (
	"fmt"
)

func main() {
	v := 1000
	for a := 1; a < v / 2; a++ {
		for b := a + 1; b < v - a; b++ {
			c := v - a - b
			if a * a + b * b == c * c {
				fmt.Printf("a: %d, b: %d, c: %d - %d\n", a, b, c, a * b * c)
			}
		}
	}
}
