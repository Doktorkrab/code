from collections import Counter
n, k = map(int, input().split())
gg = dict()

for i in range(n):
    arr = input().split()
    mn = 100000000
    who = ''
    for i in arr:
        gg[i] = gg.get(i, 0)
    for i in arr:
        if mn > gg[i]:
            mn = gg[i]
            who = i
    gg[who] += 1


for i in gg.keys():
    print(i, gg[i])