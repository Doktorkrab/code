from collections import deque

used = []
fld = []
shift = ((-1, 0), (1, 0), (0, 1), (0, -1))
def bfs(x, y):
    q = deque()
    q.append((x, y))
    while len(q):
        x, y = q.popleft()
        if used[x][y]:
            continue
        used[x][y] = 1
        for nx, ny in shift:
            if 0 <= nx + x < n and 0 <= ny + y < m and not used[nx + x][ny + y] and fld[nx + x][ny + y]:
                q.append((nx + x, ny + y))


n, m = map(int, input().split())
for i in range(n):
    fld.append(list(map(int, input().split())))
used = [[0] * m for _ in range(n)]
ans = 0
for i in range(n):
    for j in range(m):
        if not used[i][j] and fld[i][j]:
            ans += 1
            bfs(i, j)
print(ans)