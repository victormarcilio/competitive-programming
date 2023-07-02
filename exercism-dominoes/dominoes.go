package dominoes

// Define the Domino type here.
type Domino [2]int

func MakeChain(input []Domino) ([]Domino, bool) {
	if len(input) == 0 {
		return nil, true
	}
	var solution []Domino
	possible := false

	checkExtremes := func(order []Domino) bool {
		if len(order) == 0 {
			return true
		}
		return order[0][0] == order[len(order)-1][1]
	}
	var rec func([]Domino, uint64)
	rec = func(order []Domino, mask uint64) {
		if len(order) == len(input) {
			if checkExtremes(order) {
				possible = true
				solution = order[:]
			}
			return
		}
		for i := 0; i < len(input); i++ {
			if (1<<i)&mask != 0 {
				continue
			}
			if input[i][0] == order[len(order)-1][1] {
				d := Domino{input[i][0], input[i][1]}
				order = append(order, d)
				rec(order, mask|(1<<i))
				order = order[:len(order)-1]
			} else if input[i][1] == order[len(order)-1][1] {
				d := Domino{input[i][1], input[i][0]}
				order = append(order, d)
				rec(order, mask|(1<<i))
				order = order[:len(order)-1]
			}
		}
	}
	for i := 0; i < len(input) && !possible; i++ {
		rec([]Domino{input[i]}, 1<<i)
	}
	return solution, possible
}
