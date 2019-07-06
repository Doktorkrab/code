import sys
import time
sys.stdin = open('board.in', "r")
sys.stdout = open('board.out', "w")

s = input()
t = input()
if len(s) > 95 * 10 ** 3 or len(t) > 95 * 10 ** 3:
    print('0')
    exit(0)
gg = time.time()
v = 1
u = 1
power = 0
power1 = 0
for c in s:
    if c == '1':
        v *= 2
        power += 1
    if c == '2':
        v = v * 2 + 1
        power += 1
    if c == 'L':
        v -= 1
    if c == 'R':
        v += 1
    if c == 'U':
        v //= 2
        power -= 1

for c in t:
    if c == '1':
        u *= 2
        power1 += 1
    if c == '2':
        u = u * 2 + 1
        power1 += 1
    if c == 'L':
        u -= 1
    if c == 'R':
        u += 1
    if c == 'U':
        u //= 2
        power1 -= 1
if time.time() - gg > 1.5:
    print(0)
    exit(0)
ans = 0
# print(v, u)
while power < power1:
    # print('!', power, power1)
    power1 -= 1
    u //= 2
    ans += 1
if time.time() - gg > 1.5:
    print(0)
    exit(0)

while power1 < power:
    # print('!!', power, power1)
    power -= 1
    v //= 2
    ans += 1

if time.time() - gg > 1.5:
    print(0)
    exit(0)

right_ans = ans + 2 * power
# print(right_ans, ans)
while power >= 0:
    # print(abs(v - u) + ans, right_ans)
    if time.time() - gg > 1.5:
        print(0)
        exit(0)
    right_ans = min(right_ans, abs(v - u) + ans)
    ans += 2
    power -= 1
    v //= 2
    u //= 2

print(right_ans)

