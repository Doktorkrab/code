n = int(input())
s = input()
pos = [0, 0]
ans = [0, 0, 0, 0]
s1 = 'UDLR'
for i in s:
    ans[s1.index(i)] += 1

print(2 * (min(ans[:2]) + min(ans[2:])))
