def gcd(a, b):
    if not b:
        return a, 1, 0
    else:
        d, x1, y1 = gcd(b, a % b)
        return d, y1, x1 - y1 * (a // b)


a, b, c = map(int, input().split())
g = gcd(a, b)[0]
if c % g:
    print("Impossible")
    exit(0)
d, x0, y0 = gcd(a // g, b // g)
x0 *= c // g
x0 = x0 % (b // g)
y0 = (c - a * x0) // b
print(x0, y0)
