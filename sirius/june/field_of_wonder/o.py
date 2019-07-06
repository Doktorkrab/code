n = int(input())

arr = list(map(int, input().split()))
arr1 = list(map(int, input().split()))
ans = [0] * n
ans1 = [0] * n

i = 0
balls = 400
while arr[i] != 1:
    ans[i] = balls
    balls -= 1
    i += 1
ans[i] = balls
i = n - 1
balls = 1
while arr[i] != 1:
    ans[i] = balls
    balls += 1
    i -= 1

i = 0
balls = 400
while arr1[i] != 1:
    ans1[i] = balls
    balls -= 1
    i += 1
ans1[i] = balls
i = n - 1
balls = 1
while arr1[i] != 1:
    ans1[i] = balls
    balls += 1
    i -= 1

print(*ans)
print(*ans1)