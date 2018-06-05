import random
import os

while 1:
    a, b = random.randint(1, 10 ** 200)
    f = open('stress.in', 'w')
    print(a, b, file=f, sep='\n', end='')
    f.close()
    os.system('long_numbers.exe')
    f = open('stress.out')
    gg = f.readline()
    f.close()
    if not eval(str(a) + gg + str(b)):
        print(a, b)
        print(gg)
        input()
