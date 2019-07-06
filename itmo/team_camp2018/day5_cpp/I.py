n = int(input())
if n == 1:
    print('YES')
    exit(0)
arr = list(map(int, input().split()))
a = arr[0]
arr = arr[1:]
arr.sort(reverse=True)
if len(arr) > 1 and a <= arr[0] + arr[1]:
    print('NO')
else:
    print('YES')