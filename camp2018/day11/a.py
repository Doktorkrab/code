import sys
FN = 'password'
sys.stdin = open(FN + '.in')
sys.stdout = open(FN + '.out', 'w')
s = input()
t = input()
lt = len(s) - 1
r = len(t) - 1
ans_l = 0
ans_r = 1
sm = int(s[lt])
lt -= 1
len_now = 1
now = int(t[r])
last_z = 0
while lt >= 0 and r >= 0:
    # print(now, sm, len_now, lt, r)
    # if int(s[lt]) == 0:
    #     len_now += 1
    #     lt -= 1
    #     last_z = 1
    #     continue
    if sm == now:
        r -= 1
        now = int(t[r])
        sm = 0
        if len_now > 1:
            ans_l = lt + 1
            ans_r = lt + len_now + 1
        len_now = 0
    len_now += 1
    last_z = 0
    sm += int(s[lt])
    if len(str(sm)) > len(str(now)):
        r -= 1
        now = int(t[r]) * 10 * len(str(now)) + now
        # lt -= 1
    lt -= 1
    # print(now, sm, len_now, lt, r)
# print(len_now)
if len_now > 1:
    print(1, len_now)
else:
    print(ans_l + 1, ans_r)


