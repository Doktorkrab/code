from collections import Counter


def factor(x):
    i = 2
    xCopy = x
    ans = Counter()
    while i * i <= x:
        while xCopy % i == 0:
            xCopy //= i
            ans[i] += 1
        i += 1
    if xCopy > 1:
        ans[xCopy] += 1
    return ans


def isPrime(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True


ans = 1
values = []


def f(k):
    global ans, values
    ans = 1
    primes = []
    for i in range(2, 1000):
        if (isPrime(i)):
            primes.append(i)
    f = factor(k)
    values = [0] * len(primes)
    num = 0
    for k in f.keys():
        v = f[k]
        for j in range(v):
            values[num] += k - 1
            ans *= primes[num] ** (k - 1)
            num += 1

    def gen(cur):
        global ans, values
        if cur < ans:
            ans = cur
        for i in range(len(values)):
            for j in range(len(values) - 1, i, -1):
                all = (values[i] + 1) * (values[j] + 1)
                newI = 1
                while newI * newI <= all:
                    if all % newI == 0:
                        newJ = all // newI
                        newI -= 1
                        newJ -= 1
                        if newI > newJ:
                            newI, newJ = newJ, newI
                        curAns = cur
                        curAns //= primes[j] ** values[j] - newJ
                        curAns *= primes[i] ** (newI)
                        if (curAns < ans):
                            prevJ = values[j]
                            prevI = values[i]
                            values[j] = newI
                            values[i] = newI
                            gen(curAns)
                            values[i] = prevI
                            values[j] = prevJ
                        newI += 1
                    newI += 1

    gen(ans)
    return ans


'''for i in range(1, 1001):
    ans = f(i)
    fact = factor(ans)
    cnt = 1
    for v in fact.values():
        cnt *= v + 1
    if cnt == i:
        print(i, "OK", ans)
    else:
        print(i, "WA", ans)
        break
'''
print(f(int(input())))
