s = input()
q = 0
a = 0
ans = 0
for i in range(len(s)):
    for j in range(i + 1, len(s)):
        if s[j] == 'A' and s[i] == 'Q':
            ans += s[j + 1:].count('Q')
print(ans)
