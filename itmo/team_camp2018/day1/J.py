def gcd(a, b):
    if not b:
        return a, 1, 0
    else:
        d, x1, y1 = gcd(b, a % b)
        return d, y1, x1 - y1 * (a // b)

a = 9
b = int(input())
c = 1
g = gcd(a, b)[0]
if b == 1:
    print(1)
    exit(0)
if c % g:
    print("0")
    exit(0)
d, x0, y0 = gcd(a // g, b // g)
x0 *= c // g
x0 = x0 % (b // g)
y0 = (c - a * x0) // b

cnt_9 = x0
kek = b - 1
arr = []
is_9 = 0
while kek > 0:
    if kek <= 8 or (is_9 and kek == 9):
        arr.append(str(kek))
        kek = 0
        break
    if is_9:
        arr.append('9')
        kek -= 9
    else:
        arr.append('8')
        kek -= 8
        is_9 = 1
print(*arr[::-1], '9' * cnt_9, sep='')

