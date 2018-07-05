def gcd(a, b):
    if not b:
        return a, 1, 0
    else:
        d, x1, y1 = gcd(b, a % b)
        return d, y1, x1 - y1 * (a // b)


n, m = map(int, input().split())
d, x1, y1 = gcd(n, m)
if d != 1:
    print(-1)
else:
    x1 %= m
    print(x1)