import sys
EPS = 1e-7
from itertools import permutations
sys.stdin = open('twotri.in')
sys.stdout = open('twotri.out', 'w')
ax, ay, bx, by, cx, cy = map(float, input().split())
ab = ((ax - bx) ** 2 + (by - ay) ** 2) ** 0.5
bc = ((cx - bx) ** 2 + (by - cy) ** 2) ** 0.5
ac = ((cx - ax) ** 2 + (cy - ay) ** 2) ** 0.5
arr = [ab, bc, ac]
ax, ay, bx, by, cx, cy = map(float, input().split())
ab1 = ((ax - bx) ** 2 + (by - ay) ** 2) ** 0.5
bc1 = ((cx - bx) ** 2 + (by - cy) ** 2) ** 0.5
ac1 = ((cx - ax) ** 2 + (cy - ay) ** 2) ** 0.5
arr1 = [ab1, bc1, ac1]
for i in permutations(arr):
    for j in permutations(arr1):
        if abs(i[0] / j[0] - i[1] / j[1]) < EPS and abs(i[0] / j[0] - i[2] / j[2]) < EPS:
            print('YES')
            exit(0)
print('NO')