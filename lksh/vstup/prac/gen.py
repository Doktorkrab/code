import random
import os

while 1:
    n = 10
    k = random.randint(2, n)
    p = [0] * n
    f = open('photo-marathon.in', 'w')
    print(n, k, file=f)
    for i in range(1, n):
        p[i] = random.randint(0, i - 1)
        print(i + 1, p[i] + 1, file=f)
    f.close()
    os.system('./st')
    os.system('./st1')
    f = open('photo-marathon.out')
    f1 = open('photo-marathon1.out')
    ans, ans1 = int(f.readline()), int(f1.readline())
    if ans - ans1 != 0 and ans - ans1 != 1:
        print(ans - ans1)