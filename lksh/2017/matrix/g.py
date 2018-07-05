n = int(input())
arr = [[0, 1, 1, 1, 1, 1, 1, 1, 1, 1]] + [[0] * 10 for _ in range(n)]
for i in range(1, n + 1):
    for j in range(10):
        if j == 0:
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j + 1]
        elif j == 9:
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1]
        else:
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1] + arr[i - 1][j + 1]
print(sum(arr[n - 1])) 