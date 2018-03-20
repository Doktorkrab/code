import os
import random
while True:
    n = 5
    arr = []
    q = ['insert', 'delete','exists', 'prev', 'next']
    for i in range(n):
        arr.append((random.randint(0, 4), random.randint(0, 10)))
    gg = open('kek.in', 'w')
    for i in arr:
        print(q[i[0]], i[1], file=gg)
    gg = open('bstsimple.in', 'w')
    for i in arr:
        print(q[i[0]], i[1], file=gg)
    gg.close()
    hh = []
    os.system('python checker.py')
    gg = open('kek.out')
    for i in gg:
        hh.append(i)
    os.system('./treap')
    gg = open('bstsimple.out')
    kk = []
    for i in gg:
        kk.append(i)
    if hh != kk:
        for i in arr:
            print(q[i[0]], i[1])
        print('correct')
        print(*hh, sep='')
        print('invalid')
        print(*kk, sep='')
        input()

