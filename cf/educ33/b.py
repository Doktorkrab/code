n = int(input())
k = 1
ans = 0
while (2 ** k - 1) * (2 ** (k - 1)) <= n:
    if n % (2 ** k - 1) == 0 and n % (2 ** (k - 1)) == 0:
        ans = max(ans, (2 ** k - 1) * (2 ** (k - 1)))
    k += 1
print(ans)