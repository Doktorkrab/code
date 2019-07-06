import sys


def get_ans(x):
    ans = 1
    if x == 0:
        return 0
    while x > 0:
        ans *= x % 10
        x //= 10
    return ans


a = list(input())
ans = 1
cur = int(a[0])
tmp = 9 ** (len(a) - 1)
for i in a[1:]:
    now = get_ans(cur - 1)
    if cur == 1:
        now = 1
    now *= tmp
    ans = max(ans, now)
    tmp //= 9
    cur = cur * 10 + int(i)
print(max(ans, get_ans(cur)))
