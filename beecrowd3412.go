package main

import (
	"bufio"
	. "fmt"
	"os"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var N int
	Fscanln(in, &N)
	for z := 0; z < N; z++ {
		nome, _ := in.ReadString('\n')
		nome = nome[:len(nome)-1]
		notas, _ := in.ReadString('\n')
		notas = notas[:len(notas)-1]
		nr := strings.NewReader(notas)
		var nota, final float64
		score := make([]float64, 0, 4)
		for {
			_, err := Fscan(nr, &nota)
			if err != nil {
				break
			}
			score = append(score, nota)
		}
		if len(score) == 1 {
			score = append(score, 0)
		}
		if len(score) == 2 {
			final = (score[0] + score[1]) * 0.5
		} else {

			menor := 0
			if len(score) == 4 {
				for i := 1; i < 3; i++ {
					if score[i] < score[menor] {
						menor = i
					}
				}
				if score[3] > score[menor] {
					score[menor] = score[3]
				}
			}
			final = (score[0] + score[1] + score[2]) / 3
		}
		Fprintf(out, "%s: %.1f\n", nome, final)
	}
}
