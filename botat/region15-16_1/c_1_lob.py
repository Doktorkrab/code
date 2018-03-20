l = int(input())
r = int(input())
ans = 0
for i in range(l, r + 1):
    k = str(i)
    for j in range(1, len(k)):
        if k[j - 1] > k[j]:
            break
    else:
        # print(k)
        ans += 1
print(ans)