#https://www.hackerearth.com/practice/algorithms/searching/ternary-search/practice-problems/algorithm/small-factorials/
for _ in range(int(input())):
    n = int(input())
    res = 1
    for i in range(2, n + 1):
        res *= i
    print(res)
