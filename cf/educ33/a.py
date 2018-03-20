n = int(input())
playing_n = [1, 2]
spec = 3
for i in range(n):
    now = int(input())
    if now == spec:
        print('NO')
        exit(0)
    if playing_n[0] == now:
        tmp = spec
        spec = playing_n[1]
        playing_n[1] = tmp
    else:
        tmp = spec
        spec = playing_n[0]
        playing_n[0] = tmp
print('YES')
