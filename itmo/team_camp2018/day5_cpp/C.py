n = int(input())
ans = n
cnt = 2
while n - cnt >= 0:
    ans += n - cnt
    cnt += 1
print(ans)
