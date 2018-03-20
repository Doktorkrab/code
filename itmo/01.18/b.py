a, b = map(int, input().split())
arr = [-1] * 15
arr[-1] = 0
for i in range(b):
    s = ''
    # print(arr)
    for j in arr:
        if j < 0:
            continue
        s += chr(j + ord('a'))
    arr[-1] += 1
    print(s, end=' ')
    for j in range(13, -1, -1):
        if arr[j + 1] < 0:
            continue
        arr[j] += arr[j + 1] // 26
        arr[j + 1] %= 26
    if arr[0] >= 0:
        arr[0] %= 26
