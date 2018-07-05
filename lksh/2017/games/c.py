import sys

sys.stdin = open('cruel.in')
sys.stdout = open('cruel.out', 'w')
n = int(input())

dp = [0] * (n + 1)
# dp = [0, 1, 1, 2, 0]
for i in range(1, n + 1):
    set_ = set()
    for j in range(i):
        if j <= 1:
            left = 0
        else:
            left = j
        if j >= i - 2:
            right = 0
        else:
            right = i - j - 1
        set_.add(dp[left] ^ dp[right])
        # print(left, right)
    for j in range(n + 1):
        if j not in set_:
            dp[i] = j
            break
# print(*dp)
if dp[n] == 0:
    print('Mueller')
else:
    print("Schtirlitz")
    for j in range(i):
        if j <= 1:
            left = 0
        else:
            left = j
        if j >= n - 2:
            right = 0
        else:
            right = n - j - 1
        if dp[left] ^ dp[right] == 0:
            print(j + 1)
