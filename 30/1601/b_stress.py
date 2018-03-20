import random
import os


def solution(n, k, arr):
    def get_pr(l, r):
        return prefix[r] if not l else prefix[r] - prefix[l - 1]
    prefix = [0] * n
    prefix[0] = arr[0]
    for i in range(1, n):
        prefix[i] = prefix[i - 1] + arr[i]
    ans = 10 ** 18
    for i in range(n):
        ans_n = -1
        for j in range(i - k, -1, -1):
            ans_n = max(ans_n, get_pr(j, j + k - 1))
        for j in range(i + k, n - k + 1):
            ans_n = max(ans_n, get_pr(j, j + k - 1))
        ans = min(ans, ans_n)
    return ans


N = 7
while 1:
    n = random.randint(3, N)
    k = random.randint(1, n // 3)
    arr = [0] * n
    for i in range(n):
        arr[i] = random.randint(1, 10)
    kek = open("kek.in", "w")
    print(n, k, file=kek)
    print(*arr, file=kek)
    kek.close()
    os.system('./bstress')
    ans = solution(n, k, arr)
    kek = open('kek.out')
    ans1 = int(kek.readline())
    kek.close()
    if ans != ans1:
        print(n, k)
        print(*arr)
        print(ans, ans1)
        input()
