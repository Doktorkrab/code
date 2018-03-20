import random


def gcd(a, b):
    return a if not b else gcd(b, a % b)


def check(a, p):
    if gcd(a, p) > 1:
        return 0
    if pow(a, q, p) == 1:
        return 1
    for i in range(power2):
        if pow(a, powers[i] * q, p) == p - 1:
            return 1
    return 0


n = int(input())
if n == 2:
    print('YES')
    exit(0)
if not n & 1:
    print('NO')
    exit(0)
powers = [1]
power2 = 0
q = n - 1
while q % 2 == 0:
    q //= 2
    power2 += 1
    powers.append(powers[-1] * 2)
for i in range(min(373, n)):
    a = random.randint(2, n - 1)
    if not check(a, n):
        print('NO')
        exit(0)
print('YES')
