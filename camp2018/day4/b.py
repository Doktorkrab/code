import sys
p = []
sz = []
sm = []


def find(a):
    if p[a] == a:
        return a
    p[a] = find(p[a])
    return p[a]


def join(a, b, w):
    a = find(a)
    b = find(b)
    if sz[a] > sz[b]:
        a, b = b, a
    sm[b] += w
    if a == b:
        return
    p[a] = b
    sz[b] += sz[a]
    sm[b] += sm[a]


n, m = map(int, input().split())
p = [i for i in range(n)]
sz = [1 for i in range(n)]
sm = [0 for i in range(n)]
for i in range(m):
    line = list(map(int, input().split()))
    if line[0] == 1:
        join(line[1] - 1, line[2] - 1, line[3])
    else:
        print(sm[find(line[1] - 1)])
