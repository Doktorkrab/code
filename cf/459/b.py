n, m = map(int, input().split())
d = {}
for i in range(n):
    s, t = input().split()
    d[t] = s
for i in range(m):
    s, t = input().split()
    print('{} {} #{}'.format(s, t, d[t[:-1]]))
