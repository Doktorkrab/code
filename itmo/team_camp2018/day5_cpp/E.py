import math

n, m, k, d = map(float, input().split())

print(n * m - k * math.pi * (d / 2) ** 2)

