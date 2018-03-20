n, k = map(int, input().split())

arr = list(map(int, list(input())))

s = 0
ans = 0
for i in range(k - 1, n):
    s = s * 10 + arr[i]
ans = s
ind = k - 1
for i in range(k - 2, -1, -1):
    s = arr[i] * 10 ** (n - k) + (s // 10)
    if ans < s and arr[i] != 0:
        ind = i
        ans = s
s1 = 0
for i in range(n - k + 1):
    s1 += arr[ind + i]
print(sum(arr) - s1)
print(sum(arr) - s1 + ans)
