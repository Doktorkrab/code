a0 = input()
for i in range(10):
    a = a0.replace('x', str(i))
    s = ''
    i = 0
    num = ''
    zeroes = 0
    while i < len(a):
        if a[i] in '+/-()*':
            if zeroes and num == '':
                s += '0'
            else:
                s += num
            s += a[i]
            num = ''
            zeroes = 0
        else:
            # print(num, zeroes, a[i])
            if num == '' and a[i] == '0':
                zeroes = 1
            else:
                num += a[i]
        i += 1
    b = eval(s)
    print(b % 7)