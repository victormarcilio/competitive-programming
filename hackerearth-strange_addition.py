#https://blog-c7ff.kxcdn.com/pt-br/problem/algorithm/strange-addition-2/?layout=old
for i in range(int(input())):
    a = input().split()
    n1 = a[0]
    n2 = a[1]
    print(int(str(int(n1[::-1]) + int(n2[::-1]))[::-1]))
