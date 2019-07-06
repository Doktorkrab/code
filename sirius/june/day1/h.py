from collections import deque

n, m = map(int, input().split())
used = [[False] * m for _ in range(n)]
arr = [list(map(int, input().split())) for _ in range(n)]
ans = 0


def bfs(v, u):
    q = deque()
    q.append((v, u))
    have_lower = 0
    shift = ((-1, 0), (1, 0), (0, 1), (0, -1))
    if used[v][u]:
        return
    while len(q):
        x, y = q.popleft()
        if used[x][y]:
            continue
        used[x][y] = True
        for nx, ny in shift:
            if 0 <= nx + x < n and 0 <= ny + y < m:
                if arr[nx + x][y + ny] == arr[x][y]:
                    q.append((nx + x, ny + y))
                elif arr[nx + x][y + ny] < arr[x][y]:
                    # print(arr[x][y], arr[nx + x][ny + y], x, y)
                    have_lower = 1
            # print(x, y, arr[x][y], arr[nx][ny])
    global ans
    ans += 1 - have_lower
    # print(v, u, have_lower)


for i in range(n):
    for j in range(m):
        bfs(i, j)
# bfs(1, 1)
print(ans)
# for i in used:
    # print(i)