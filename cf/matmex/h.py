def fact(n):
    oldn = n
    ans = [1, n, {}]
    tmp = {}
    for i in range(2, int(oldn ** 0.5) + 10):
        while n % i == 0:
            n //= i
            tmp[i] = tmp.get(i, 0) + 1
    if n != 1:
        tmp[n] = tmp.get(n, 0) + 1
    for i in tmp:
        ans[0] *= (tmp[i] + 1)
    while oldn > 0:
        ans[2][oldn % 10] = ans[2].get(oldn % 10, 0) + 1
        oldn //= 10
    return ans


n = int(input())
arr = list(map(int, input().split()))
d = {}
for i in arr:
    d[i] = d.get(i, 0) + 1
ans = 10 ** 9
ans1 = 0
for i in range(1, 10 ** 5 + 1):
    gg = fact(i)
    for i in gg[2]:
        if gg[2][i] > d.get(i, 0):
            break
    else:
        if ans > gg[0]:
            ans1 = gg[1]
            ans = gg[0]
print(ans, ans1, sep='\n')
