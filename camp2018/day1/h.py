import sys
sys.stdin = open('park.in')
sys.stdout = open('park.out', 'w')
n = int(input())
d = set()
ans = 0
for i in range(n):
    x, y = map(int, input().split())
    ans += 4
    # print(d, (x - 1, y), (x + 1, y), (x, y + 1), (x, y - 1))
    if (x - 1, y) in d:
        ans -= 2
        # print('heh')
    if (x + 1, y) in d:
        ans -= 2
        # print('heh')
    if (x, y + 1) in d:
        ans -= 2
        # print('heh')
    if (x, y - 1) in d:
        ans -= 2
        # print('heh')
    d.add((x, y))
print(ans)