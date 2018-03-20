import sys
sys.setrecursionlimit(10 ** 9)
def g(a):
    hh = list(map(int, list(str(a))))
    gg = 1
    for j in hh:
        if j != 0:
            gg *= j
    return gg
def f(a):
    # print(a)
    if a < 10:
        return a
    # print(a, g(a), '!')
    return f(g(a))


l, r, k = map(int, input().split())
# print(g(10))
cnt = 0
for i in range(l, r + 1):
    # print(f(i))
    if f(i) == k:
        print(i)
        cnt += 1
print()
print(cnt)