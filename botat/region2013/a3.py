a, b, c, d = map(int, input().split())
ans = 0
for i in range(1, int(b ** 0.5) + 1):
    mn = max((c + 1) // 2 - i, (a + i - 1) // i, i)
    mx = min(d // 2 - i, b // i)
    if mn <= mx:
        ans += mx - mn + 1
print(ans)
