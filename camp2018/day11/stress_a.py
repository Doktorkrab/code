import random
import os

while 1:
    n = random.randint(1, 10 ** 4)
    l = random.randint(0, len(str(n)) - 1)
    r = random.randint(0, len(str(n)) - 1)
    if l > r:
        l, r = r, l
    f = open('password.in', 'w')
    n = str(n)
    print(n, file=f)
    ans = 0
    newn = ''
    for i in range(len(n)):
        if not ans and not (l <= i <= r):
            newn += n[i]
        elif l <= i <= r:
            ans += int(n[i])
        else:
            newn += str(ans) + n[i]
            ans = 0
    if ans:
        newn += str(ans)
    print(newn, file=f)
    f.close()
    os.system('./a')
    os.system('python a.py')
    f_right = open('password.out1')
    f_not = open('password.out')
    right = list(map(int, f_right.readline().split()))
    bot_r = list(map(int, f_not.readline().split()))
    if right != bot_r:
        print(n)
        print(newn)
        print(l + 1, r + 1)
        print(right)
        print(bot_r)
        input()
