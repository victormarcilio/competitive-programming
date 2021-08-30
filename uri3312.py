#https://www.urionlinejudge.com.br/judge/pt/problems/view/3312
import math
primes = [2]
for i in range(3, 100):
    eh = True
    for prime in primes:
        if i % prime == 0:
            eh = False
            break
    if eh:
        primes.append(i)
input()
for r in map(int,(input().split())):
    if r in primes:
        print(f"{r}! = {math.factorial(r)}")