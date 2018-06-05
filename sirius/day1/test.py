n = 5
m = 9
arr = [[0] * m for _ in range(n)]

arr[0][0] = 1

for i in range(n):
    for j in range(m):
        if i == j == 0:
            continue
        if (i, j) == (2, 0) or (i, j) == (1, 6):
            arr[i][j] = 0
            continue
        if i != 0:
            arr[i][j] += arr[i - 1][j]
        if j != 0:
            arr[i][j] += arr[i][j - 1]
print(arr[4][8])