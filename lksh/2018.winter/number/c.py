def gcd(a, b):
    if not b:
        return a, 1, 0
    else:
        d, x1, y1 = gcd(b, a % b)
        return d, y1, x1 - y1 * (a // b)


def crt(a, b, n, m):
    d, x1, y1 = gcd(n, m)
    if a % d != b % d:
        print('NO')
        return
    print('YES', (b * x1 * n // d + a * m * y1 // d) % (n * m // d), n * m // d)

n = int(input())
for i in range(n):
    a, b, n, m = map(int, input().split())
    crt(a, b, n, m)