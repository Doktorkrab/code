def get_prefix(l, r):
    return prefix[r] - prefix[l - 1] if l else prefix[r]


n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
arr1 = []
cnt = 1
for i in range(1, n):
    if arr[i - 1] != arr[i]:
        arr1.append((arr[i - 1], cnt))
        cnt = 1
    else:
        cnt += 1
arr1.append((arr[n - 1], cnt))
arr1.sort()
pnt = 0
n = len(arr1)
ans = 0
for i in range(n):
    arr1[i] = (arr1[i][0], arr1[i][1], int(arr1[i][1] >= 2))
    if arr1[i][1] >= 3:
        ans += 1
prefix = [0] * n
for i in range(n):
    prefix[i] = arr1[i][2] + prefix[i - 1]
for i in range(n):
    while pnt < n - 1 and arr1[pnt + 1][0] <= arr1[i][0] * k:
        pnt += 1
    # print(pnt)
    ans += 6 * (pnt - i) * (pnt - i - 1) // 2 + 3 * get_prefix(i + 1, pnt) + 3 * (pnt - i if arr1[i][2] else 0)
print(ans)
