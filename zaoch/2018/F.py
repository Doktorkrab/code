import sys
def gcd(a, b):
    if not b:
        return a, 1, 0
    else:
        d, x1, y1 = gcd(b, a % b)
        return d, y1, x1 - y1 * (a // b)


def crt(a, b, n, m):
    d, x1, y1 = gcd(n, m)
    if a % d != b % d:
        return -1
    return (b * x1 * n // d + a * m * y1 // d) % (n * m // d)

def main():
    n = int(sys.stdin.readline())
    a = list(map(lambda x : int(x) - 1, sys.stdin.readline().split()))
    b = list(map(lambda x : int(x) - 1, sys.stdin.readline().split()))
    kost = [-1] * (n + 1)
    used = [0] * n
    kto = []
    for i in range(n):
        if used[i]:
            continue
        cnt = 1
        now = i
        while not used[now] and a[now] != b[i]:
            used[now] = 1
            now = a[now]
            cnt += 1
        if a[now] != b[i]:
            sys.stdout.write('No\n')
            exit(0)
        now1 = i
        cnt1 = 0
        while used[now] != 2 and a[now] == b[now1]:
            used[now] = 2
            now = a[now]
            now1 = a[now1]
            cnt1 += 1
        if a[now] != b[now1]:
            sys.stdout.write('No\n')
            exit(0)
        if kost[cnt1] != -1 and kost[cnt1] != cnt % cnt1:
            sys.stdout.write('No\n')
            exit(0)
        if kost[cnt] != -1:
            continue
        kost[cnt1] = cnt % cnt1
        kto.append((cnt % cnt1, cnt1))


    for i in range(len(kto)):
        for j in range(len(kto)):
            if i == j:
                continue
            ans = crt(kto[i][0], kto[j][0], kto[i][1], kto[j][1])
            if ans == -1:
                sys.stdout.write('No\n')
                exit(0)
    sys.stdout.write('Yes\n')

main()