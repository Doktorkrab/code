n, k, x = map(int, input().split())

arr = list(map(int, input().split()))
ans = 0
for i in range(n - 1, -1, -1):
    if k:
        ans += x
        k -= 1
    else:
        ans += arr[i]
print(ans)