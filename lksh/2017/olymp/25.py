n = int(input())
arr = list(map(int, input().split()))
bal = 0
for i in arr:
    if i == 1:
        bal += 1
    else:
        bal -= 1
if not bal:
    print('YES')
else:
    print('NO')