import sys

FN = 'i'
sys.stdin = open(FN + '.in')
sys.stdout = open(FN + '.out', 'w')
n = int(input())
arr = list(map(int, input().split()))

d = {}


def bins(i, now):
	l, r = 0, len(d[now])
	while r - l > 1:
		m = (l + r) // 2
		if d[now][m] <= (n // 2 + i) % n:
			l = m
		else:
			r = m
	return d[now][l]


def bins1(i, now):
	l, r = 0, len(d[now])
	while r - l > 1:
		m = (l + r) // 2
		if d[now][m] <= (n // 2 + i) % n:
			l = m
		else:
			r = m
	return d[now][l]


def dist(a, b):
	if a > b:
		a, b = b, a
	return min(b - a, a + 1 + n - b)

ans, l, r = 0, -1, -1
for i in range(n):
	if arr[i] not in d:
		d[arr[i]] = [i]
		continue
	a = bins(i, arr[i])
	b = bins1(i, arr[i])
	# print(arr[i], i, a, b)
	if dist(i, a) > ans:
		ans = dist(i, a)
		l = i
		r = a
	if dist(i, b) > ans:
		ans = dist(i, b)
		l, r = i, b
	d[arr[i]].append(i)
print(l + 1, r + 1)