n = int(input())
dp = [1, 1]
while dp[-1] < n:
    dp.append(dp[-1] + dp[-2])
for i in range(1, n + 1):
    if i in dp:
        print('O', end='')
    else:
        print('o',end='')