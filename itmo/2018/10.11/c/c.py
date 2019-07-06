import math
w, h = map(int, input().split())

a, b, c, d = map(lambda x : int(x) ** 2, input().split())

print(w * h - (a + b + c + d) * (1 - math.pi / 4))