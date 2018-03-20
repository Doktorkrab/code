import sys
sys.stdin = open('kek.in')
sys.stdout = open('kek.out', 'w')
s = set()
for i in sys.stdin:
    q, x = i.split()
    if q == "insert":
        s.add(int(x))
    if q == "delete":
        s.discard(int(x))
    if q == "exists":
        print('true' if int(x) in s else 'false')
    if q == "next":
        mn = 10 ** 9 + 1000
        for j in s:
            if j > int(x):
                mn = min(j, mn)
        print('none' if mn == 10 ** 9 + 1000 else mn)
    if q == "prev":
        mx = - (10 ** 9 + 1000)
        for j in s:
            if j < int(x):
                mx = max(j, mx)
        print('none' if mx == -(10 ** 9 + 1000) else mx)
