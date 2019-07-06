from collections import deque



n  = int(input())

arr = [[] for _ in range(n)]

m  = int(input())
g = [[] for _i in range(m)]
dist = [10 ** 9] * m

for i in range(m):
    tmp = list(map(lambda x : int(x) - 1, input().split()))[1:]
    for j in tmp:
        for k in arr[j]:
            g[k].append(i)
            g[i].append(k)
        arr[j].append(i)

q = deque()
a, b = map(lambda x : int(x) - 1, input().split())
for i in arr[a]:
    dist[i] = 0
    q.append(i)

while len(q):
    v = q.popleft()
    for u in g[v]:
        if dist[u] > dist[v] + 1:
            dist[u] = dist[v] + 1
            q.append(u)
mn = 10 ** 9
for i in arr[b]:
    mn = min(dist[b], mn)
print(mn)