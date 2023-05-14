package main

import (
	"fmt"
)

func main() {
	var E, F, C, ans int
	fmt.Scan(&E, &F, &C)
	latas := E + F
	for {
		curr := latas / C
		if curr == 0 {
			break
		}
		latas = latas%C + curr
		ans += curr
	}
	fmt.Println(ans)
}
