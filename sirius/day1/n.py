import heapq
n = int(input())

arr = list(map(int, input().split()))
m = int(input())
g = [[] for _ in range(n)]
for i in range(m):
    v, u = map(lambda x: int(x) - 1, input().split())
    g[v].append((u, arr[v]))
    g[u].append((v, arr[u]))

heap = []
heapq.heappush(heap, (0, 0))
dp = [10 ** 18] * n
used = [0] * n
dp[0] = 0
while len(heap):
    _, u = heapq.heappop(heap)
    if used[u]:
        continue
    used[u] = 1
    for v, pr in g[u]:
        if dp[v] > dp[u] + arr[u]:
            dp[v] = dp[u] + arr[u]
            heapq.heappush(heap, (dp[v], v))
print(-1 if dp[n - 1] == 10 ** 18 else dp[n - 1])