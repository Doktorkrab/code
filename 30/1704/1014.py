def get_factorization(n):
    sqrt_n = int(n ** 0.5)
    f = 2
    factorization = {}
    while n > 1 and f <= sqrt_n:
        while n % f == 0:
            factorization[f] = factorization.get(f, 0) + 1
            n //= f
        f += 1
    if n > 1:
        factorization[n] = factorization.get(n, 0) + 1
    return factorization


def check(req, fact):
    for dg in req:
        if fact.get(dg, 0) < req[dg]:
            return False
    for dg in req:
        fact[dg] -= req[dg]
    return True


digits = {
    9: {3: 2},
    8: {2: 3},
    6: {3: 1, 2: 1},
    4: {2: 2}
}

n = int(input())
if n == 1:
    print(1)
    exit(0)
if n == 0:
    print(10)
    exit(0)
fact = get_factorization(n)
digits_list = [9, 8, 6, 4]
for digit in digits_list:
    while check(digits[digit], fact):
        fact[digit] = fact.get(digit, 0) + 1
# print(fact)
ans = []
for i in fact:
    if i > 10:
        print(-1)
        exit(0)
    for j in range(fact[i]):
        ans.extend(list(str(i)))
print(''.join(sorted(ans)))
