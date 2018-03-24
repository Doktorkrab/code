import random
import os
n = 5


def prime(n):
    if n == 1:
        return True
    cnt = {}
    f = 2
    oldn = int(n ** 0.5) + 1
    while f <= oldn:
        while n % f == 0:
            cnt[f] = cnt.get(f, 0) + 1
            n //= f
        f += 1
    if n > 1:
        cnt[n] = cnt.get(n, 0) + 1
    return len(cnt) == 1 and cnt[list(cnt.keys())[0]] > 1
# print(prime(2), prime(4), prime(1), prime(8))
while 1:
    f = open('stress.in', 'w')
    print(5, file=f)
    arr = []
    for i in range(5):
        a, b = random.randint(1, 100), random.randint(1, 100)
        if a > b:
            a, b = b, a
        print(a, b, file=f)
        arr.append((a, b))
    f.close()
    os.system('python c.py')
    f = open('stress.out')
    for i in range(5):
        a, b = arr[i]
        ans = 0
        for i in range(a, b + 1):
            if prime(i):
                ans += 1
                # print(i)
        gg = int(f.readline())
        if ans != gg:
            print(a, b)
            print(ans, gg)
            for i in range(a, b + 1):
                if prime(i):
                    # ans += 1
                    print(i, end=' ')
            print()
            input()
        print('success')
    f.close()
