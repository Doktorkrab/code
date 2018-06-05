n, m = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]

dp = [[10 ** 18] * m for _ in range(n)]

dp[0][0] = 0

for i in range(n):
    for j in range(m):
        if i != 0:
            dp[i][j] = dp[i - 1][j]
        if j != 0:
            dp[i][j] = min(dp[i][j], dp[i][j - 1])
        dp[i][j] += arr[i][j]
print(dp[-1][-1])