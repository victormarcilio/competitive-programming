#https://www.urionlinejudge.com.br/judge/pt/problems/view/3309
feliz = set()
triste = set()
felizes = 0

def check(number, seen):
    global felizes
    if number in seen:
        triste.update(seen)
    else:
        total = 0
        seen.add(number)
        for digit in str(number):
            total += int(digit) ** 2
        if total == 1 or total in feliz:
            feliz.update(seen)
            felizes += 1
        elif total not in triste:
            check(total, seen)

input()
for number in map(int, input().split()):
    if number in feliz:
        felizes += 1
    elif number not in triste:
        check(number, set())
print(felizes)