a, k, b, m1, x = map(int, input().split())


def check(m):
    if k == m1:
        return (a + b) * (m - m // k) >= x
    return b * (m // k) + a * (m // m1) + (a + b) * (m - m // k - m // m1) >= x


def bin_search():
    l, r = 0, 10 ** 18 * 9
    while r - l > 1:
        m = (l + r) // 2
        if check(m):
            r = m
        else:
            l = m
    print(r)


bin_search()