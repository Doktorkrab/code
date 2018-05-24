n = int(input())
arr = list(map(int, input().split()))
kek = len(set(arr))
qni = 0
l = 0
d = [0] * (5 * 10 ** 5 + 1)
ans = 0

for r in range(n):
    if d[arr[r]] == 0:
        qni += 1
    d[arr[r]] += 1
    while l <= r and not (r - l + 1 == qni or (r - l == qni and qni < kek)):
        if d[arr[l]] == 1:
            qni -= 1
        d[arr[l]] -= 1
        l += 1
    # print(l, r)
    ans = max(ans, abs(r - l) + 1)
print(ans)
