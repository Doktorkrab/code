n, x = map(int, input().split())
ans = 0
for i in range(1, x + 1):
    ans ^= i
    print(bin(ans)[2:], i)