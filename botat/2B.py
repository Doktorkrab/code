import math
n = int(input())

dp = [[0, 0, 0] for _ in range(n)]
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
