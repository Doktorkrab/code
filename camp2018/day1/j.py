import sys
sys.stdin = open('path.in')
sys.stdout = open('path.out', 'w')
def dfs(v):
    used[v] = 1
    for u in g[v]:
        if not used[u]:
            dfs(u)


n, m = map(int, input().split())
M = int(input())
g = [[] for _ in range(n)]
for i in range(m):
    v, u, w = map(int, input().split())
    if w < M:
        continue
    g[v - 1].append(u - 1)
    g[u - 1].append(v - 1)
used = [0] * n
dfs(0)
print("YES" if used[n - 1] else "NO")