import sys
sys.stdin = open('tower.in')
sys.stdout = open('tower.out', 'w')

n = int(input())
arr = []
for i in range(n):
    sz, c = input().split()
    arr.append((int(sz), c))
arr.sort()
d = {'R': 0, 'G': 0, 'B': 0}
d[arr[0][1]] += 5 * arr[0][0] * arr[0][0]
for i in range(1, n):
    d[arr[i][1]] += 5 * arr[i][0] * arr[i][0] - arr[i - 1][0] * arr[i - 1][0]
print('R - {0}\nG - {1}\nB - {2}'.format(d['R'], d['G'], d['B']))
