n = int(input())
m = int(input())
k = int(input())

ans = (m + k // n - 1) // (k // n)
print(ans)