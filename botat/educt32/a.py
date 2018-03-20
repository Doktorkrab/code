n = int(input())
arr = list(map(int, input().split()))
ans = 0
for i in range(1, n - 1):
    if arr[i - 1] > arr[i] and arr[i + 1] > arr[i]:
        ans += 1
    elif arr[i - 1] < arr[i] and arr[i + 1] < arr[i]:
        ans += 1
print(ans) 