while True:
    try:
        for _ in range(int(input())):
            print(chr(int(input(), 2)), end='')
        print()
    except EOFError:
        break
