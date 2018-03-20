n = int(input())

gg = sum(map(int, input().split()))
gg1 = list(map(int, input().split()))
gg1.sort()
if gg1[-1] + gg1[-2] >= gg:
    print('YES')
else:
    print('NO')
