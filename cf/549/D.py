from math import gcd

n, k = map(int, input().split())
a, b = map(int, input().split())

l = n * k
x, y = 10 ** 18, -1
for i in range(n):
    end = i * k + b + 1
    start = a + 1
    ll = (end - start)
    if ll < 0:
        ll += l
    gg = l // gcd(ll, l)
    x = min(x, gg)
    y = max(y, gg)
    end = (i + 1) * k - b + 1
    ll = (end - start)
    if ll < 0:
        ll += l
    gg = l // gcd(ll, l)
    x = min(x, gg)
    y = max(y, gg)
print(x, y)

