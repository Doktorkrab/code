t = int(input())


def kek(a):
    if a <= 0:
        return 0
    return 1


for i in range(t):
    a, b = map(int, input().split())
    mod = a % b
    ans = 0
    for j in range(b, 0, -1):
        ans += ((a // b + kek(mod)) * (a // b)) * (j - 1) + max(0, mod - 1) * (a // b + kek(mod))
        mod -= 1
    print(ans)
