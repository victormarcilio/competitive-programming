package main

import (
	"fmt"
)

func main() {
	var N, T int
	var time string
	fmt.Scan(&N)
	for i := 0; i < N; i++ {
		fmt.Scan(&T, &time)
		if time[0] == '1' {
			if T > 45 {
				fmt.Printf("45+%d\n", T-45)
			} else {
				fmt.Println(T)
			}
		} else {
			if T > 45 {
				fmt.Printf("90+%d\n", T-45)
			} else {
				fmt.Println(45 + T)
			}
		}
	}
}
