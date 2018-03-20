n = int(input())
d = {}
for i in range(n):
    s = input()
    i = 0
    num = ''
    while i < len(s):
        if s[i] in '0123456789':
            while i < len(s) and s[i] in '0123456789':
                num += s[i]
                i += 1
        i += 1
    d[int(num)] = d.get(int(num), 0) + 1
ans = 0
for i in d:
    if d[i] <= 5:
        ans += 1
print(ans)
for i in d:
    if d[i] <= 5:
        print(i)