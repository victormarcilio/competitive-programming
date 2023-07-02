
// https://app.codesignal.com/company-challenges/datto/EqY2nxWWakbu3NTon
func solution(threads int, documents []int) int {
	best := 500000
	var rec func(int, int, []int, []int)
	rec = func(threads, doc int, documents, work []int) {
		if doc == len(documents) {
			worst := 0
			for _, wk := range work {
				if wk > worst {
					worst = wk
				}
			}
			if worst < best {
				best = worst
			}
			return
		}
		for i := 0; i < threads; i++ {
			work[i] += documents[doc]
			rec(threads, doc+1, documents, work)
			work[i] -= documents[doc]
		}
	}
	rec(threads, 0, documents, make([]int, threads))
	return best
}
