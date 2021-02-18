# This exercise has a little trick that is not explicited in the
# statement: There might be more than one row with the same color
# in the input! That is why I used the dictionary

def factorial(x):
    answer = 1
    for i in range (2, x + 1):
        answer *= i
    return answer

rows = int(input())
numerator = 0
denominator = 1
dic = dict()
for _ in range(rows):
    row = input().split()
    color = row[0]
    amount = int(row[1])
    numerator += amount
    if color in dic.keys():
        dic[color] += amount
    else:
        dic[color] = amount
for entry in dic.values():
    denominator *= factorial(entry)

print("Feliz aniversario Tobias!\n%d" % (factorial(numerator)/denominator))
        