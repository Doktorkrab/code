import sys
sys.stdin = open('biology.in')
sys.stdout = open('biology.out', 'w')
t = input()
s = input()
l = 0
r = 0
while l < len(t) and r < len(s):
    if s[r] == t[l]:
        l += 1
    r += 1
print("YES" if l == len(t) else 'NO')