import sys
FN = 'calendar'
# sys.stdin = open(FN + '.in')
# sys.stdout = open(FN + '.out', 'w')
n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]
ans = [0 if arr[0][i] == '*' else int(arr[0][i]) for i in range(m)]
for i in range(1, n):
    if arr[i][-1] != '*':
        ans[-1] = int(arr[i][-1]) - i
        ans[-1] %= 10
        break
for i in range(m - 2, -1, -1):
    na = []
    sz = 0
    for j in range(1, n):
        if arr[j][i] != '*':
            na = arr[j]
            sz = j
            break
    if not na:
        continue
    for j in range(i + 1, m):
        if na[j] == '*':
            # print(j, i)
            na[j] = sz // (10 ** (m - j - 1)) % 10
        else:
            na[j] = int(na[j])
    ans[-1] = na[-1] - sz

    for j in range(m - 1, i, -1):
        ans[j - 1] = int(na[j - 1]) + ans[j] // 10
        ans[j] %= 10
    ans[i] %= 10
print(''.join(list(map(str, ans))))
