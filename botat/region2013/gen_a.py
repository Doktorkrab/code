import random
import os


def solution(a, b, c, d):
    ans = 0
    for i in range(1, int(b ** 0.5) + 1):
        mn = max((c + 1) // 2 - i, (a + i - 1) // i, i)
        mx = min(d // 2 - i, b // i)
        if mn <= mx:
            ans += mx - mn + 1
    return ans
# solution(16, 16, 1, 10 ** 6)


while 1:
    a, b, c, d = [random.randint(4, 10) for _ in range(4)]
    if a > b:
        a, b = b, a
    if c > d:
        c, d = d, c
    ff = open('kek.in', 'w')
    print(a, b, c, d, file=ff)
    ff.close()
    os.system('./yakush_')
    ff = open('kek.out')
    ans = int(ff.readline())
    ff.close()
    ans1 = solution(a, b, c, d)
    if ans != ans1:
        print(a, b, c, d)
        print('Excepted', ans1, "Found", ans)
        input()
