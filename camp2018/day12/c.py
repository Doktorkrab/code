import sys
n, m = map(int, input().split())
x, y = map(int, input().split())
cnt = 0
while x > 1 and y > 1:
    print(-1, -1, 1)
    x -= 1
    y -= 1
    sys.stdout.flush()
    a, b, c = map(int, input().split())
    cnt += 1
    if a == 1:
        exit(0)
while x > 1:
    print(-1, 0, 1)
    x -= 1
    sys.stdout.flush()
    a, b, c = map(int, input().split())
    cnt += 1
    if a == 1:
        exit(0)
while y > 1:
    print(0, -1, 1)
    y -= 1
    sys.stdout.flush()
    a, b, c = map(int, input().split())
    cnt += 1
    if a == 1:
        exit(0)
cur_x = 1
# print('heh')
while cnt < 10000:
    while 1 < x + cur_x < n:
        print(cur_x, 0, 1)
        sys.stdout.flush()
        a, b, c = map(int, input().split())
        cnt += 1
        if a == 1:
            exit(0)
        x += cur_x
    cur_x *= -1
    if y < n:
        y += 1
        print(0, 1, 1)
        sys.stdout.flush()
        a, b, c = map(int, input().split())
        cnt += 1
        if a == 1:
            exit(0)

print(0, 0, 1)
sys.stdout.flush()
