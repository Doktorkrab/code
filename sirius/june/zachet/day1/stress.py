import os
import random

while 1:
    n = 5
    m = 5
    arr = [random.randint(0, 5) for i in range(n)]
    querys = []
    for i in range(m):
        q = random.randint(1, 2)
        l, r = random.randint(1, n), random.randint(1, n)
        if l > r:
            l, r = r, l
        querys.append((q, l, r, random.randint(-5, 5)))
    f = open('stress.in', 'w')
    arr1 = [i for i in arr]
    print(n, m, file=f)
    print(*arr, file=f)
    for i in querys:
        print(*i, file=f)
    f.close()
    os.system('./y < stress.in')
    ans = []
    for i in querys:
        if i[0] == 1:
            tmp = 0
            for j in range(i[1] - 1, i[2]):
                if arr[j] < i[3]:
                    tmp += 1
            ans.append(tmp)
        else:
            for j in range(i[1] - 1, i[2]):
                arr[j] += i[3]
    f = open('stress.out')
    ans1 = [int(x) for x in f]
    f.close()
    if ans != ans1:
        print(n, m)
        print(*arr1)
        print(*arr, 'debug')
        for i in querys:
            print(*i)
        print(*ans)
        print(*ans1)
        input()