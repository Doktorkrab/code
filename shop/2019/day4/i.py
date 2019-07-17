s = input()

d = [{} for _ in range(2)]
n = len(s)
for i in range(n):
    d[i % 2][s[i]] = d[i % 2].get(s[i], 0) + 1

odd_cnt = 0
for i in d[0]:
    odd_cnt += d[0][i] % 2

# if odd_cnt ^ (n % 2):
#     print('NO!')
#     exit(0)

odd = ''
if n % 2:
    dd = {}
    for i in d[0]:
        dd[i] = d[0].get(i, 0) - d[1].get(i, 0)

    ones = 0
    gg = ''
    for i in dd:
        if dd[i] != 0 and dd[i] != 1:
            print(dd[i])
            print('NO0')
            exit(0)
        if dd[i] == 1:
            ones += 1
            gg = i
    if ones > 1:
        print('NO1')
        exit(0)
    odd = gg
    d[0][gg] -= 1
if d[0] != d[1]:
    print('NO2')
    exit(0)

ans = ['' for _ in range(n)]
pnt = 0
pnt1 = n - 1
if n % 2:
    ans[n // 2] = odd
    pnt1 += 1

for i in d[0]:
    while d[0][i] > 0:
        ans[pnt] = i
        d[0][i] -= 1
        ans[pnt1] = i
        d[1][i] -= 1
        pnt += 1
        pnt1 -= 1
print(''.join(ans))