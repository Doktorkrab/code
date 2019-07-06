def gcd(a, b):
    if not b:
        return a, 1, 0
    else:
        d, x1, y1 = gcd(b, a % b)
        return d, y1, x1 - y1 * (a // b)


def check(x):
    f = 2
    oldx = x
    while f * f <= oldx:
        if x % f == 0:
            return 0
        f += 1
    return 1


n, k = map(int, input().split())

primes = []
primes1 = []
kek = []
f = 2
while len(primes) < n:
    if check(f):
        kek.append(f ** k - len(primes))
        primes.append(f ** k)
        primes1.append(f)
    f += 1

M = 1
for i in primes:
    M *= i

x = 0
for i in range(n):
    x += kek[i] * (M // primes[i]) * (gcd(M // primes[i], primes[i])[1] % primes[i])
print(x)
for i in range(n):
    print(primes1[i])