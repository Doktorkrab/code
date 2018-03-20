from math import gcd

a, b, c, d = map(int, input().split())
g = gcd(gcd(a, b), gcd(c, d))
a //= g
b //= g
c //= g
d //= g
a1, b1, c1, d1 = map(int, input().split())
g = gcd(gcd(a1, b1), gcd(c1, d1))
a1 //= g
b1 //= g
c1 //= g
d1 //= g
if a1 == 0 or b1 == 0 or c1 == 0:
    print(0)
elif d1 != 0 and a / a1 == b / b1 == c / c1 == d / d1:
    print(2)
elif a / a1 and b / b1 == c / c1 != d / d1 or (d1 == 0 and a / a1 and b / b1 == c / c1):
    print(0)
else:
    print(1)
