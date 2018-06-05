import string
s = input()

ans = 0
word = 0

for i in range(len(s)):
    if s[i] in string.ascii_letters:
        word = 1
    elif s[i] == '-' and word and i != len(s) - 1 and s[i + 1] in string.ascii_letters:
        word = 1
    else:
        ans += word
        word = 0
print(ans + word)