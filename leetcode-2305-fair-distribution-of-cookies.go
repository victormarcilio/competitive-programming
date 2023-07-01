//https://leetcode.com/problems/fair-distribution-of-cookies/description/
var best int

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func rec(i, k int, cookies, acc []int) {
    if i == len(cookies) {
        worst := 0
        for _, c := range acc {
            worst = max(worst, c)
        }
        best = min(worst, best)
        return
    }
    for j := 0; j < k; j++ {
        acc[j] += cookies[i]
        rec(i + 1, k, cookies, acc)
        acc[j] -= cookies[i]
    }
}

func distributeCookies(cookies []int, k int) int {
    for _, c := range cookies {
        best += c
    }
    acc := make([]int, k)
    rec(0, k, cookies, acc)
    return best
}
