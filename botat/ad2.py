n = int(input())
d = {}
ans = 0
for i in range(n):
    a, b, c = input().split()
    arr = [a, b, c]
    arr.sort()
    if (d.get((arr[0], arr[1]), 0) > 0):
        ans += d[(arr[0], arr[1])]
    if (d.get((arr[0], arr[2]), 0) > 0):
        ans += d[(arr[0], arr[2])]
    if (d.get((arr[1], arr[2]), 0) > 0):
        ans += d[(arr[1], arr[2])]
    d[(arr[0], arr[1])] = d.get((arr[0], arr[1]), 0) + 1
    d[(arr[0], arr[2])] = d.get((arr[0], arr[2]), 0) + 1
    d[(arr[1], arr[2])] = d.get((arr[1], arr[2]), 0) + 1
print(ans)
