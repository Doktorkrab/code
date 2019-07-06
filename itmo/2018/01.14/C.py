def lazy(x):
	if x < 0:
		return 0
	if dp[x] != -1:
		return dp[x]
	for i in range()
n, m = map(int, input().split())
arr = [0] * n
dp = [-1] * (10 ** 6 + 5)
dp[0] = 1
pos = -1
for i in range(n):
	arr[i] = int(input())
	if arr[i] == m:
		pos = i
for i in range(n):
	if pos == i:
		continue
	if m % arr[i] == 0:
		print('-1')
		exit(0)


