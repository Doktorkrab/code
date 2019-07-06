v1, v2 = map(int, input().split())
l1, l2 = map(int, input().split())

a = l1 * v1 + l2 * v1
b1 = l1 * v1
c = v2 * (l1 + l2)
b2 = -l1 * v2

ans = 0
gg = 9e5
while ans < gg:
	if (ans * a + b1) % c == 0:
		print("YES")
		exit(0)
	if (ans * a + b2) % c == 0:
		print("YES")
		exit(0)
	ans += 1
print('NO')