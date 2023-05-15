package main

import (
	"fmt"
)

func main() {
	var N, L, D int
	fmt.Scan(&N, &L, &D)
	L *= 1000
	ans := L
	need := N * D
	for ans < need {
		ans += L
	}
	fmt.Println(ans / 1000)
}
