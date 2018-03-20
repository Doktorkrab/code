a, b, c, d = map(int, input().split())
s = min(a, b) + min(c, d)
print(int(s ** 0.5))