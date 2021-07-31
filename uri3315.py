ans = 0
for _ in range(4):
    ans = max(ans, sum(map(int, input().split())))
print (ans, '=', "{0:b}".format(ans))
