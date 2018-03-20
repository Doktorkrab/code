n = int(input())
arr = list(map(int, list(input())))

cnt0 = 0
cnt1 = 0
gg = {0: -1}
ans = 0
for i in range(n):
    if arr[i] == 0:
        cnt0 += 1
    else:
        cnt1 += 1
    ans = max(ans, i - gg.get(cnt0 - cnt1, i))
    gg[cnt0 - cnt1] = min(i, gg.get(cnt0 - cnt1, i + 1))
print(ans)