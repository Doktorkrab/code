import sys
sys.stdin = open('bigset.in')
sys.stdout = open('bigset.out', 'w')
n, m = map(int, input().split())


def check(gg):
    ans = 0
    for i in range(1, m + 1):
        ans += gg // i
    return ans >= n


def bins():
    l, r = 0, n
    while r - l > 1:
        m = (l + r) // 2
        if check(m):
            r = m
        else:
            l = m 
    print(r)
bins()
