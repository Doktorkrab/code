import sys


def pr(type):
    for i in arr[type]:
        print(arr1[type], i)


sys.stdin = open("b.in")
sys.stdout = open("b.out", 'w')
n = int(input())
types = {"A": 0, "AB": 1, "B": 2, "BC": 3, "C": 4, "ABC": 5}
arr1 = ["A", "AB", "B", "BC", "C", "ABC"]
arr = [[] for _ in range(6)]
types_cnt = 0
for i in range(n):
    type, s = input().split(maxsplit=1)
    if len(arr[types[type]]) == 0:
        types_cnt += 1
    arr[types[type]].append(s)
if len(arr[5]) > 0:
    if len(arr[2]) > 0:
        if len(arr[0]) > 0 and len(arr[4]) > 0:
            print("Impossible")
        elif len(arr[0]) > 0:
            pr(0)
            pr(1)
            pr(5)
            pr(3)
            pr(2)
        elif len(arr[4]) > 0:
            pr(2)
            pr(1)
            pr(5)
            pr(3)
            pr(4)
            exit(0)
        else:
            pr(1)
            pr(5)
            pr(3)
            pr(2)
    else:
        pr(0)
        pr(1)
        pr(5)
        pr(3)
        pr(4)
else:
    for i in range(6):
        pr(i)