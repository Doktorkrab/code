import sys
sys.stdin = open('gas.in')
sys.stdout = open('gas.out', 'w')
n, b = map(int, input().split())
ans = 0
arr = [tuple(map(int, input().split())) for _ in range(n)]
dp = [10 ** 24] * n
dp[0] = 0
for i in range(1, n):
    for j in range(i - 1, -1, -1):
        if arr[i][0] - arr[j][0] > b:
            break
        dp[i] = min(dp[j] + (arr[i][0] - arr[j][0]) * arr[j][1], dp[i])
print(dp[-1] if dp[-1] != 10 ** 24 else -1)