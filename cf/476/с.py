def check(m, plus):
    return n % (plus + m) >= k


def bin_s(plus):
    l, r = 1, k
    while r - l > 1:
        m = (l + r) // 2
        if check(m, plus):
            l = m
        else:
            r = m
    return l


n, k, m, d = map(int, input().split())
print("!!!")
ans = 0
for i in range(1, d + 1):
    plus = k * (i - 1)
    print(i, ans)
    if plus >= n:
        break
    mod = bin_s(plus)
    if plus + mod > n:
        break
    if n % (plus + mod) >= k:
        break
    print(plus, mod, i, n // (plus + mod) * i)
    ans = max(ans, n // (plus + mod) * i)
print(ans)