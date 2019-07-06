a = int(input())
n = int(input())
arr1 = list(map(int, input().split()))
arr = []
for i in arr1:
    if i < a:
        continue
    arr.append(i)
arr.sort()
dp = [1] * n
ans = 0
n = len(arr)
for i in range(n):
    dp[i] = 1
    for j in range(i - 1, -1, -1):
        # print(-1)
        if arr[j] + 3 <= arr[i]:
            dp[i] = max(dp[i], dp[j] + 1)
    if arr[i] >= a:
        ans = max(ans, dp[i])
print(ans)