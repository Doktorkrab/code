import sys
n, k = map(int, input().split())
dp = [[0] * 4 for _ in range(n + 1)]
dp[0] = [0, 0, 0, 1]
# if n == 2 and k == 1:
#     s = input()
#     if s == '2 1':
#         print(8)
#         exit(0)
#     exit(1)
# if k != 0:
#     exit(1)
MOD = 10 ** 9 + 7
accepted_masks = [[0, 1, 2, 3] for _ in range(n + 1)]
for i in range(k):
    x, y = map(int, input().split())
    if 0 in accepted_masks[x]:
        accepted_masks[x].pop(accepted_masks[x].index(0))
    if y == 2:
        accepted_masks[x].pop(accepted_masks[x].index(2))
    else:
        accepted_masks[x].pop(accepted_masks[x].index(1))
for i in range(1, n + 1):
    if len(accepted_masks[i]) == 4:
        dp[i][0] = dp[i - 1][3]
        dp[i][1] = dp[i - 1][3] + dp[i - 1][2]
        dp[i][2] = dp[i - 1][3] + dp[i - 1][1]
        dp[i][3] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + (2 * dp[i - 1][3]) % MOD
    else:
        # print(accepted_masks[i])
        if accepted_masks[i][0] == 2:
            dp[i][2] = dp[i - 1][3]
            dp[i][3] = dp[i - 1][2] + dp[i - 1][3]
        elif accepted_masks[i][0] == 1:
            dp[i][1] = dp[i - 1][3]
            dp[i][3] = dp[i - 1][1] + dp[i - 1][3]
        else:
            dp[i][3] = dp[i - 1][3]
    for j in range(4):
        dp[i][j] %= MOD
# print(*dp, sep='\n', file=sys.stderr)
print(dp[n][3])
