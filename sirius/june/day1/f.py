n, m = map(int, input().split())

months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31]

print(sum(months[:m - 1]) + n)