n, m, k = map(int, input().split())
print((2 ** (n - 1) * 2 ** (m - 1)) % (10 ** 9 + 7))