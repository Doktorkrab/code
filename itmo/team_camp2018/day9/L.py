import math
a, p = map(int ,input().split())

for i in range(1, 101):
    if (2 * i - 100) * (100 - p) - a * p - 100 >= 0:
        print(i)
        exit(0)
print('Impossible')