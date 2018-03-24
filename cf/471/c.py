import sys
import math
FN = 'stress'
# sys.stdin = open(FN + '.in')
# sys.stdout = open(FN + '.out', 'w')
coof = [10 ** 9, 1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0, -1, 1, 0, 0]


EPS = 1e-7


def get_prefix(m):
    if m == 0:
        return 0
    ans = 0
    for i in range(2, 64):
        t = int(pow(m, 1 / i))
        print(t, m, i)
        if t == 1:
            break
        ans += coof[i] * -1
    return ans


n = int(input())
# n = 1
for i in range(n):
    a, b = map(int, input().split())
    print(get_prefix(b) - get_prefix(a - 1) + int(a == 1))