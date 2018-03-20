MOD = 10 ** 9 + 7


def get(gg):
    gg = str(gg)
    coof = n - len(gg)
    # dp1 = [[0] * 10 for _ in range(len(gg))]
    # dp1[0][gg[0] - 1] = 1
    ans = sum(dp[coof][:int(gg[0])])
    for i in range(1, len(gg)):
        if gg[i - 1] > gg[i]:
            break
        for j in range(int(gg[i - 1]), int(gg[i])):
            ans += dp[coof + i][j]
            ans %= MOD
    else:
        ans += int(gg != '0')
    return ans % MOD


# l, r = map(int, input().split())
l = int(input())
r = int(input())
n = max(len(str(l)), len(str(r)))
dp = [[0] * 10 for _ in range(n)]
dp[n - 1] = [1] * 10
dp[n - 1][0] = 0
for i in range(n - 2, -1, -1):
    for j in range(10):
        for k in range(j, 10):
            dp[i][j] += dp[i + 1][k]
            dp[i][j] %= MOD
# print(*dp, sep='\n')
print((get(r) - get(l - 1)) % MOD)
