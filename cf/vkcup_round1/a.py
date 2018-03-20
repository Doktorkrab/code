def gg(a):
    f = 2
    heh = 0
    old_a = a ** 0.5
    while f * f <= old_a:
        # print('f', f, a)
        if a % f == 0:
            heh = f
        while a > 0 and a % f == 0:
            a //= f
        f += 1
    if a > 1:
        heh = max(heh, a)
    return heh


a = ['1'] * (10 ** 6 + 1)
for i in range(2, 10**6 + 1):
    a[i] = str(gg(i))
    # print(i)
print('{', ','.join(a), '}', sep='')