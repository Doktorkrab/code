s = input()
d = [{} for _ in range(2)]
n = len(s)
if n == 3:
    print('YES' if s[0] == s[2] else 'NO')
    exit(0)
if n % 2 == 0:
    d = [{} for _ in range(2)]
    for i in range(n):
        d[i % 2][s[i]] = d[i % 2].get(s[i], 0) + 1

    # if odd_cnt ^ (n % 2):
    #     print('NO!')
    #     exit(0)

    odd = ''
    if d[0] != d[1]:
        print('NO')
        exit(0)

    ans = ['' for _ in range(n)]
    pnt = 0
    pnt1 = n - 1

    while pnt < pnt1:
        now = list(d[0].keys())[0]
        ans[pnt] = now
        ans[pnt1] = now
        d[0][now] -= 1
        if (d[0][now] == 0):
            d[0].pop(now)
        pnt += 1
        pnt1 -= 1
    print(''.join(ans))
else:
    for i in range(n):
        d[i % 2][s[i]] = d[i % 2].get(s[i], 0) + 1
    for i in d[1]:
        if d[1][i] % 2:
            print("NO")
            exit(0)

    odd = ''
    odd_cnt = 0
    for i in d[0]:
        if d[0][i] % 2:
            odd_cnt += 1
            odd = i
    if odd_cnt != 1:
        print('NO')
    ans = ['' for _ in range(n)]
    ans[n // 2] = odd
    d[0][odd] -= 1
    pnt = 0
    pnt1 = n - 1
    # print(ans)
    while pnt != pnt1:
        # print(pnt, pnt1)
        now = list(d[pnt % 2].keys())[0]
        ans[pnt] = now
        ans[pnt1] = now
        d[pnt % 2][now] -= 2
        if d[pnt % 2][now] == 0:
            d[pnt % 2].pop(now)
        pnt += 1
        pnt1 -= 1
    print(''.join(ans))

