import sys
FN = 'tax'
sys.stdin = open(FN + '.in')
sys.stdout = open(FN + '.out', 'w')
n, z = map(int, input().split())
p = [None] + list(map(int, input().split()))
x = [0] + list(map(int, input().split())) + [int(5e24)]


def check(m):
    ans = 0
    for i in range(1, n + 1):
        if x[i] >= m:
            ans += p[i] * (m - x[i - 1]) // 100
            # print(ans)
            return ans >= z
        else:
            ans += p[i] * (x[i] - x[i - 1]) // 100


def bins():
    l = 0
    r = 10 ** 20
    while r - l > 1:
        m = (l + r) // 2
        if check(m):
            r = m
        else:
            l = m
    print(r)
    # print(check(l), check(r))


# print(check(533334))
bins()
