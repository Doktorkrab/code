n = int(input())

if n == 2:
	print(0)
	exit(0)

ans = [0]
gg = 0
for i in range(1, n - 1):
	ans.append(-i)
	gg += i
print(*ans, gg)