def check(m):
    w1 = m // w
    h1 = m // h
    return w1 * h1 < n


w, h, n = map(int, input().split())
l, r = 0, 10 ** 18
while r - l > 1:
    m = (l + r) // 2
    if check(m):
        l = m
    else:
        r = m
print(r)