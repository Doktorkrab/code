import random
import os

X = 5


def solution(a, k, b, m, x):
    ans = 0
    for i in range(1, 1000):
        ans += 1
        if i % k:
            x -= a
        if i % m:
            x -= b
        if x <= 0:
            break
    return ans


while 1:
    x = random.randint(1, X)
    a, k, b, m = random.randint(1, X), random.randint(2, X), random.randint(1, X), random.randint(2, X)
    ff = open('kek.in', 'w')
    print(a, k, b, m, x, file=ff)
    ff.close()
    os.system('python b.py')
    ff = open('kek.out')
    ans = int(ff.readline())
    ff.close()
    ans_r = solution(a, k, b, m, x)
    if ans != ans_r:
        print('test: ', a, k, b, m, x)
        print('right: ', ans_r)
        print('found:', ans)
        input()
