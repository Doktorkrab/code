def check(s):
    if s[0] == '0':
        return False
    return ord('a') <= int(s) <= ord('z') or ord('A') <= int(s) <= ord('Z')


s = input()
n = len(s) // 3
variants = [[0] * n for _ in range(10)]
kek = [0] * n
for i in range(n):
    now = s[3 * i:3 * i + 3]
    kek[i] += int(check(now))
    for j in range(10):
        variants[j][i] += int(check(now))
        lol = set()
        for k in range(3):
            if int(now[k]) == j:
                if check(now[0:k] + now[k + 1:3]) and chr(int(now[0:k] + now[k + 1:3])) not in lol:
                     variants[j][i] += 1
                     lol.add(chr(int(now[0:k] + now[k + 1:3])))
MOD = 10 ** 9 + 7
ans = 0
for i in range(10):
    tmp = variants[i][0]
    for j in variants[i][1:]:
        tmp = (tmp * j) % MOD
    if tmp > 0:
        ans -= min(kek)
    ans += tmp
    ans = ans % MOD
print((ans + min(kek)) % MOD)
