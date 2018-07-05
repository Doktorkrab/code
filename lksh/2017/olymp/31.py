n, t, d = map(int, input().split())
v = list(map(int, input().split()))
ans = d / v[0]
# print(d / v[0])
for i in range(1, n):
    ans_n = 0
    t_n = 0
    for j in range(i):
        ans_n += t * v[j]
        t_n += t
    # print(i, ans_n, t_n, '!')
    if 2 * t_n + t > ans:
        continue
    to_drive = d - 2 * ans_n
    if v[i] == 0:
        continue
    if to_drive / v[i] < t:
        continue
    # print(to_drive, to_drive / v[i], t_n, '~')
    t_n += to_drive / v[i] + t_n
    if t_n < ans:
        ans = t_n
print('{:.16f}'.format(ans)) 