h1, m1, h2, m2 = map(int, input().split())

if h1 == h2:
    if m1 < 30 and m2 > 30:
        print(1)
    else:
        print(0)
else:
    ans = 0
    for i in range(h1 + 1, h2 + 1):
        ans += i + 1
    ans -= 1
    # print(ans)
    if m1 < 30:
        ans += 1
    if m2 > 30:
        ans += 1
    print(ans)
