n, m = map(int, input().split())
d = {}
ans = 3e9
ans_n = ''
for i in range(n):
    s = input()
    gg = sum(map(int, input().split()))
    if gg < ans:
        ans_n = s
        ans = gg
print(ans_n)