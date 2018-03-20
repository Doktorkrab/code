import sys
sys.stdin = open('theblackpearl.in')
sys.stdout = open('theblackpearl.out', 'w')
s = input()
ans = 0
questions = 0
start = 0
cur = 0
while start < len(s) and s[start] == '?':
    cur += 1
    start += 1
if start < len(s):
    cur_s = s[start]
    cur += 1
for i in range(start + 1, len(s)):
    if cur_s != s[i] and s[i] != '?':
        ans += cur * (cur + 1) // 2
        # print(cur_s, cur, questions, cur * (cur + 1) // 2)
        cur_s = s[i]
        cur = 1 + questions
        ans -= questions * (questions + 1) // 2
        questions = 0
    else:
        if s[i] == '?':
            questions += 1
        else:
            questions = 0
        cur += 1
# print(cur, cur_s)
ans += cur * (cur + 1) // 2
print(ans)
