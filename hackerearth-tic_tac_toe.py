MOD = 1000000007
for i in range(int(input())):
    n = int(input())
    x1 = n//2 *(n//2) % MOD
    n2 = n - 1
    x2 = n2 * (n2 + 1) * (2*n2 + 1)//6
    print(x1 * n % MOD, x2 % MOD)
