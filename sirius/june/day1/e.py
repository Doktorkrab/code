s = [int(i) for i in list(input())]

ans = sum(s)
print('YES' if ans % 3 == 0 else 'NO')