text = input().split()
input()
words = input().split()
for word in words:
    current_pos = 0
    positions = []
    for i in range(len(text)):
        if word == text[i]:
            positions.append(current_pos)
        current_pos += len(text[i]) + 1
    if len(positions):
        print(" ".join(map(str,positions)))
    else:
        print(-1)

        