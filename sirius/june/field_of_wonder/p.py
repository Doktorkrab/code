s = input()
t = input()

for i in range(len(s)):
    j = i
    k = 0
    while k < len(t) and s[j] == t[k]:
        k += 1
        j = (j + 1) % len(s)
    if k == len(t):
        print('YES')
        exit(0)
    j = i
    k = 0
    while k < len(t) and s[j] == t[k]:
        k += 1
        j = (j - 1) % len(s)
    if k == len(t):
        print('YES')
        exit(0)    
print('NO')