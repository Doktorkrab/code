import os


def check(a):
    for i in range(2, int(a ** 0.5) + 1):
        if a % i == 0:
            return False
    return True


for i in range(2, 10 ** 6):
    ff = open('kek.in', 'w')
    print(i, file=ff)
    ff.close()
    kek = check(i)
    os.system('python d.py')
    ff1 = open('kek.out')
    kek1 = ff1.readline() == 'YES\n'
    # print(i)
    ff1.close()
    if kek != kek1:
        print(i, 'Excepted:', kek, 'Found:', kek1)
        input()
