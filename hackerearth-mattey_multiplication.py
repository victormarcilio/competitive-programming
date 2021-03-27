#https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/mattey-multiplication-6/
for _ in range(int(input())):
    n, m = map(int, input().split())
    mul = n * m
    first = False
    for i in range(100, -1, -1):
        if n << i <= mul:
            if first:
                print(" + ", end="")
            first = True
            print("(%d<<%d)" % (n, i), end ='')
            mul -= (n << i)
    print()
