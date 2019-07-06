n, m = map(int, input().split())
if n == m == 2:
    print(1)
    print(1, 1)
    print(1, 1)
    exit(0)
if n % 4 == 0:
    now = 0
    ans = ''
    mx = 0
    for i in range(1, n + 1):
        s = ''
        for j in range(1, m + 1):
            s += str(now + j) + ' '
            mx = max(now + j, mx)
        if i % 4 == 0:
            now += m
        ans += s + '\n'
    print(mx)
    print(ans)
elif m % 4 == 0:
    now = 1
    ans = ''
    mx = 0
    for i in range(1, n + 1):
        s = ''
        for j in range(1, m + 1):
            s += str(now) + ' '
            mx = max(mx, now)
            if j % 4 == 0:
                now += 1
        ans += s + '\n'
    print(mx)
    print(ans)
elif n % 2 == 0 and m % 2 == 0:
    print(n * m // 4)
    now = 1
    for i in range(n // 2):
        for j in range(m):
            print(now + j // 2, end=' ')
        print()
        for j in range(m):
            print(now + j // 2, end=' ')
        print()
        now += m // 2
else:
    print(-1)