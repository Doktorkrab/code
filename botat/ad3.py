import sys
import threading
threading.stack_size((1 << 23) - 1)
sys.setrecursionlimit(10 ** 9)


def dfs(v, h):
    if depth[v] != -1:
        return
    depth[v] = h
    # print(v)
    for u in g[v]:
        size[v] += dfs(u, h + 1)
    return size[v]


n, k = 0, 0
depth, size, g = [], [], []


def dfs1(v):
    global k
    if not k:
        return
    k -= 1
    print(v + 1, end=' ')
    for u in g[v]:
        if not k:
            return
        dfs1(u)


def main():
    global n
    global k
    global g
    global size
    global depth
    n, k = map(int, input().split())
    g = [[] for _ in range(n)]
    size = [1] * n
    depth = [-1] * n
    if n - 1:
        prev = list(map(lambda x: int(x) - 1, input().split()))
        for i in range(1, n):
            # print(i)
            g[prev[i - 1]].append(i)
        # print("that's all")
    dfs(0, 0)
    max_, max_ind = -1, -1
    for i in range(n):
        if size[i] >= k and depth[i] > max_:
            max_ = depth[i]
            max_ind = i
    dfs1(max_ind)
    print()


th = threading.Thread(target=main)
th.start()
th.join()
