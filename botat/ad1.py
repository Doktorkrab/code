def check(a, b, c, name):
    if a[2] + a[1] + b[1] + c[1] + c[0] >= h:
        print('YES')
        print(name, '- Superman!')
        exit(0)
    else:
        return h - (a[0] + a[1] + b[1] + c[1] + c[2])


h = int(input())
arr = [list(map(int, input().split())) for _ in range(3)]
ans = 10 ** 9
ans = min(ans, check(arr[2], arr[1], arr[0], 'Dmitry'))
ans = min(ans, check(arr[1], arr[2], arr[0], 'Dmitry'))
ans = min(ans, check(arr[0], arr[2], arr[1], 'Vladislav'))
ans = min(ans, check(arr[2], arr[0], arr[1], 'Vladislav'))
ans = min(ans, check(arr[0], arr[1], arr[2], 'Piece of Lard'))
ans = min(ans, check(arr[1], arr[0], arr[2], 'Piece of Lard'))
print('NO')
print(ans)
