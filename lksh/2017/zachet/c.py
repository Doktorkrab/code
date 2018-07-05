a, b, c = map(int, input().split())
g = [0] * max(a + 1, b + 1, c + 1)
g[1] = 0
for i in range(2, max(a, b, c) + 1):
    s = set()
    for j in range(i // 2 + i % 2, i):
        s.add(g[j])
    for j in range(1, len(s) + 1):
        if j not in s:
            g[i] = j
            break
    # print(i, s, g[i])
print(g)
if not g[a] ^ g[b] ^ g[c]:
    print('NO')
else:
    for j in range(a // 2 + a % 2, a):
        if g[j] ^ g[b] ^ g[c] == 0:
            print('YES')
            print(j, b, c)
            break
    else:
        for j in range(b // 2 + b % 2, b):
            if g[a] ^ g[j] ^ g[c] == 0:
                print('YES')
                print(a, j, c)
                break
        else:
            for j in range(c // 2 + c % 2, c):
                if g[a] ^ g[b] ^ g[j] == 0:
                    print('YES')
                    print(a, b, j)
                    break
            else:
                print('NO')
