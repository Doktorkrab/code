import sys


def ask(x, y):
    print(x, y)
    sys.stdout.flush()
    return input().startswith('w')


n = int(input())
if n == 1:
    print(1, 1)
    print(0, 0, 1, 0)
    sys.stdout.flush()
    exit(0)
arr = [(1, 0), (1, 1)]
colors = [ask(*x) for x in arr]

swapped = 0
if colors[0] == colors[1]:
    swapped = 1
down = 0
up = 1

for i in range(2, n):
    x_p, y_p = 1 << (i - 1), down + up
    color = 0
    if not swapped:
        color = ask(x_p, y_p)
    else:
        color = ask(y_p, x_p)
    if colors[1] == color:
        up = down + up
        down = 2 * down
    else:
        down = down + up
        up = 2 * up
    # print(up, down, '!')
x_p, y_p = 1 << (n - 1), down + up
if swapped:
    x_p, y_p = y_p, x_p
print(0, 0, x_p, y_p)
sys.stdout.flush()
