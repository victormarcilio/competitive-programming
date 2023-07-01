//https://www.beecrowd.com.br/judge/pt/problems/view/3433
package main

import . "fmt"

func value(card int) int {
	if card > 9 {
		return 10
	}
	return card
}

func main() {
	var N int
	Scan(&N)
	remaining := make(map[int]int)
	for i := 1; i < 14; i++ {
		remaining[i] = 4
	}

	var c1, c2 int
	Scan(&c1, &c2)
	joao := value(c1) + value(c2)
	remaining[c1]--
	remaining[c2]--
	Scan(&c1, &c2)
	maria := value(c1) + value(c2)
	remaining[c1]--
	remaining[c2]--

	for i := 0; i < N; i++ {
		Scan(&c1)

		joao += value(c1)
		maria += value(c1)
		remaining[c1]--
	}
	ans := -1

	for i := 1; i < 14; i++ {
		if remaining[i] > 0 && check(joao+value(i), maria+value(i)) {
			ans = i
			break
		}
	}
	Println(ans)
}

func check(joao, maria int) bool {
	return maria == 23 || joao > 23 && maria < 23
}
