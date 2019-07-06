int(input())
arr = list(map(int, input().split()))
a, b = arr[0], arr[1]
MOD = 10 ** 9 + 7
print((a - b) % MOD)