import sys
sys.stdin = open('points.in')
sys.stdout = open('points.out', 'w')
w, h, w1, h1 = map(int, input().split())
s = w * h
s1 = w1 * h1
i = s - (w + h) + 1
i1 = s1 - (w1 + h1) + 1
# print(s, s1, i, i1)
print(i - i1 - 2 * (h1 + w1))