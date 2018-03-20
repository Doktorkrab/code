n, k, s, x = map(int, input().split())
INF = 10 ** 9
dp = [INF] * n
dp[s] = 0
gg = s
while dp[(gg + k) % n] == INF and gg != x:
    # print(gg)
    dp[(gg + k) % n] = dp[gg] + 1
    gg = (gg + k) % n
if dp[x] == INF:
    print(-1)
else:
    print(dp[x])
