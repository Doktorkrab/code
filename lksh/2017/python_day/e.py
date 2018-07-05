import random
2

def gcd(a, b):
    return a if not b else gcd(b, a % b)


def check(a, p, powers, power2, q):
    if gcd(a, p) > 1:
        return 0
    if pow(a, q, p) == 1:
        return 1
    for i in range(power2):
        if pow(a, powers[i] * q, p) == p - 1:
            return 1
    return 0


def is_prime(n):
    if n == 2:
        return 1
        exit(0)
    if not n & 1:
        return 0
        exit(0)
    powers = [1]
    power2 = 0
    q = n - 1
    # print(n, "JOOOOOOOOPA")
    while q % 2 == 0:
        # print(q)
        # input()
        q //= 2
        power2 += 1
        powers.append(powers[-1] * 2)
    for i in range(min(373, n)):
        a = random.randint(2, n - 1)
        if not check(a, n, powers, power2, q):
            return 0
            # exit(0)
    return 1


def f(a, n):
    return (a ** 2 + 2) % n


n = int(input())
k = int(n ** 0.5)
cnt = 0
arr1 = []
arr = [n]
if is_prime(n):
    print(n)
    exit(0)
# print(arr)
while len(arr):
    # print(len(arr))
    # print(arr[len(arr) - 1], 'lol')
    kek = arr[len(arr) - 1]
    start = random.randint(0, arr[len(arr) - 1] - 1)
    cnt = 0
    # print(len(arr), 'kek', arr)
    # print(kek)
    x0, x1 = start % kek, f(start, kek)
    g = gcd((x0 - x1) % arr[len(arr) - 1], arr[len(arr) - 1])
    f1 = 0
    while cnt < max(k, 100):
        if 1 < g < n:
            # print(arr[-1])
            arr.pop(len(arr) - 1)
            # print(arr, arr1, 'before', g, kek // g)
            if is_prime(g):
                arr1.append(g)
            else:
                arr.append(g)
            if kek // g == 1:
                break
            if is_prime(kek // g):
                arr1.append(kek // g)
            else:
                arr.append(kek // g)
            # print(arr, arr1)
            # input()
            break
        x0, x1 = f(x0, kek), f(f(x1, kek), kek)
        g = gcd(abs(x0 - x1), kek)
        cnt += 1
print(*sorted(arr1), sep='\n')
