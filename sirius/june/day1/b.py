n, k = map(int, input().split())
# k = max(1, k)
arr = list(map(int, input().split()))

prefix = [10 ** 18] * n
ind = [10 ** 18] * n
for i in range(n):
    if i == 0:
        prefix[i] = arr[i]
        ind[i] = 0
        continue
    if prefix[i - 1] < arr[i]:
        prefix[i] = arr[i]
        ind[i] = i
    else:
        ind[i] = ind[i - 1]
        prefix[i] = prefix[i - 1]

ans = 0
ans1 = (10 ** 18, 10 ** 18)
for i in range(k + 1, n):
    # print(ans, arr[i] + prefix[i - k])
    if ans < prefix[i - k - 1] + arr[i]:
        ans1 = (ind[i - k - 1], i)
    ans = max(arr[i] + prefix[i - k - 1], ans)

print(ans1[0] + 1, ans1[1] + 1)
# print(ans, prefix)
# print(ind)
