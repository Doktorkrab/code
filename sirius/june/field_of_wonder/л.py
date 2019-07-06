arr = list(map(int, input().split()))
arr.sort()

s = sum(arr)

if s < 2:
    print(1)
    exit(0)

k = 0
while s > 4:
    s -= arr[-1]
    arr.pop(len(arr) - 1)
    k+= 1
print(k)