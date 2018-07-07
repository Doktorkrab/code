import subprocess
import random

def get_sz(v, p):
    sz = 1
    for u in g[v]:
        if (v + 1, u + 1) in banned or u == p or (u + 1, v + 1) in banned:
            continue
        sz += get_sz(u, v)
    return sz
banned = set()
while 1:
    n = 5
    p = random.randint(1, n)
    edg = []
    s = str(n) + ' ' + str(p) + '\n'
    for i in range(2, n + 1):
        edg.append((i, random.randint(1, i - 1)))
        s += str(edg[-1][0]) + ' ' + str(edg[-1][1]) + '\n'
    pr = subprocess.Popen('./c', stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)
    data = pr.communicate(input=s)[0]
    g = [[] for _ in range(n)]
    for v, u in edg:
        g[v - 1].append(u - 1)
        g[u - 1].append(v - 1)
    global ans
    ans = [1001]
    ans1 = {}
    for mask in range(1, 2 ** (n - 1)):
        for i in range(n - 1):
            if mask & (2 ** i) == 0:
                continue
            banned.add(edg[i])
        for i in range(n):
            gg = get_sz(i, -1)
            if gg == p or gg == n - p:
                if len(banned) < ans[0]:
                    ans[0] = len(banned)
                    ans1 = set()
                    for j in banned:
                        ans1.add(j)
                break
        for i in range(n - 1):
            if mask & (2 ** i) == 0:
                continue
            banned.discard(edg[i])
        continue
    if n == p:
        ans[0] = 0
    if data == '' or int(data) != ans[0]:
        print(n, p)
        edg.sort()
        for i in edg:
            print(*i)
        print()
        print(ans, int(data))
        print(ans1)
        input()
    print('ok')