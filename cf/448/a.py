n = int(input())


def get(l, r):
    if not l:
        return pr[r]
    return pr[r] - pr[l - 1]


arr = list(map(int, input().split()))
gg = 360
ans = 360
pr = [0] * n
pr[0] = arr[0]
for i in range(1, n):
    pr[i] = arr[i] + pr[i - 1]
for i in range(n):
    for j in range(i, n):
        if abs(i - j) == n - 1:
            continue
        s = get(i, j)
        ans = min(ans, abs(360 - s - s))
print(ans)
