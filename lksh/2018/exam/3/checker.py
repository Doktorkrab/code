import sys
sys.stdin = open('test')

n, l, r = map(int, input().split())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))


sys.stdin = open('corr_ans')

n1 = int(input())
s = 0
for i in map(int, input().split()):
    s += arr[i - 1][1]


sys.stdin = open('my_ans')

s1 = 0
n2 = int(input())

for i in map(int, input().split()):
    s1 += arr[i - 1][1]

if s != s1:
    print('corr:', s)
    print('my:', s1)
    exit(1)