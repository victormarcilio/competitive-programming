package main

import (
	"bufio"
	. "fmt"
	"os"
)

func termSum(terms int64) int64 {
	return terms*(terms-1)/2 + terms*(1+terms)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var T, N int64
	Fscan(in, &T)
	for T > 0 {
		Fscan(in, &N)
		var left, mid, right int64

		left = 0
		right = 1000000000
		for right-left > 1 {
			mid = (left + right) / 2
			res := termSum(mid)
			if res == N {
				break
			}
			if res < N {
				left = mid
			} else {
				right = mid
			}
		}
		for termSum(mid) > N {
			mid--
		}
		for termSum(mid+1) <= N {
			mid++
		}
		T--
		Fprintln(out, mid)
	}
}
