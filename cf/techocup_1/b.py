n, m = map(int, input().split())
ans = set()
d = {}
for i in range(m):
    k, f = map(int, input().split())
    d[k] = f
for i in range(1, 101):
    floor = 1
    cur_floor = 0
    ans_floor = 0
    for j in range(1, 101):
        if cur_floor == i:
            floor += 1
            cur_floor = 0
        if d.get(j, floor) != floor:
            break
        if j == n:
            ans_floor = floor
        cur_floor += 1
    else:
        ans.add(ans_floor)
if len(ans) > 1 or len(ans) == 0:
    print(-1)
else:
    print(*ans)

