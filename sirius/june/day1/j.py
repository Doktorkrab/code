import sys

n = int(input())

arr = []

for i in range(n):
    name, surname, a, b, c = input().split()
    a = int(a)
    b = int(b)
    c = int(c)
    arr.append(((a + b + c) / -3, i, name, surname))
arr.sort()
for i in arr:
    print(i[-2], i[-1])
