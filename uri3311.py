#https://www.urionlinejudge.com.br/judge/pt/problems/view/3311
print('\n'.join([*map(lambda x: x[0], sorted([(input(), i) for i in range(int(input()))], key=lambda x: (x[0][0], x[1])))]))
