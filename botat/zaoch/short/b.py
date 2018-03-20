import sys


def main():
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    print(a)
    need = [0] * (n + 1)
    can_up = [1] * (n + 1)
    for i in range(1, n + 1):
        print(i, len(need), len(a))
        need[i] = need[i - 1] * a[i - 1] + 1
        can_up[i] = a[i - 1] * can_up[i - 1]
    xes = sys.stdin.readline().split()
    for x in xes:
        y = int(x)
        level = n
        ans = 0
        while y != 0:
            ans += need[level] * (y // can_up[level]) + 1
            y %= can_up[level]
            level -= 1
        sys.stdout.write(str(ans - 1) + '\n')


main()