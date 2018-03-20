import sys
p = []
sz = []


def reset(n):
    global p
    p = [i for i in range(n)]
    global sz
    sz = [1 for i in range(n)]
    print('RESET DONE')


def find(a):
    if p[a] == a:
        return a
    p[a] = find(p[a])
    return p[a]


def join(a, b):
    olda, oldb = a, b
    a = find(a)
    b = find(b)
    if a == b:
        print("ALREADY", olda, oldb)
        return
    if sz[a] > sz[b]:
        a, b = b, a
    p[a] = b
    sz[b] += sz[a]


for i in sys.stdin:
    arr = i.split(' ')
    if arr[0] == 'RESET':
        reset(int(arr[1]))
    elif arr[0] == 'JOIN':
        join(int(arr[1]), int(arr[2]))
    elif arr[0] == 'CHECK':
        a, b = find(int(arr[1])), find(int(arr[2]))
        print('YES' if a == b else 'NO')
