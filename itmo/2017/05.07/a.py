import sys
sys.stdin = open('frozen.in')
sys.stdout = open('frozen.out', 'w')
n = int(input())

pnt = list(map(int, input().split()))
pnts = [set() for _ in range(n)]
arr = list(map(int, input().split()))
for i in range(n * 2):
    pnts[i % n].add(arr[i])
ans = 0
pnts = [list(sorted(list(pnts[i]))) for i in range(n)]
for i in range(n):
    ans += int(pnts[i][0] != 0) + int(len(pnts[i]) > 1 and pnts[i][1] != pnt[i] and pnts[i][1] != 0) 
print(ans)
