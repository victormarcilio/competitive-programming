// https://www.beecrowd.com.br/judge/pt/problems/view/3428
package main

import (
	"bufio"
	. "fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var flechas [5000001]int
	var N, H int
	Fscan(in, &N)
	ans := 0
	for i := 0; i < N; i++ {
		Fscan(in, &H)
		if flechas[H] > 0 {
			flechas[H]--
			flechas[H-1]++
		} else {
			flechas[H-1]++
			ans++
		}
	}
	Println(ans)
}
