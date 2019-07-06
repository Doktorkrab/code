k, n, l = map(int, input().split())

mn = 1
p = 1
for i in range(l):
    gg = (n + p - 1) // p
    mn += gg
    # print((n + p - 1) // p)
    if gg != 1:
        p *= k

if n <= k:
    print(mn, 1 + l * n)
    exit(0)
n -= k
mx = 1 + l * k
prev = k
for i in range(1, l):
    max_cnt = prev * (k - 1)
    prev *= k
    max_cnt = min(max_cnt, n)
    mx += (l - i) * max_cnt
    n -= max_cnt
    if n == 0:
        break
print(mn, mx)
