a = input()
if len(a) * 2 <= 10 ** 4:
    print(a + a[::-1])
else:
    print(a)