n = int(input())

ans = 2 * n - 1
s = ['.'] * ans

l, r = ans // 2, ans // 2
while l >= 0:
    s[l] = '*'
    s[r] = '*'
    print(*s, sep='')
    l -= 1
    r += 1
