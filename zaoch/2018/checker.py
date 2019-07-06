#!/usr/bin/python3

import sys
def getValue(x):
	ans = 1
	if x == 0:
		return 0
	while x > 0:
		ans *= x % 10
		x //= 10
	return ans


args = sys.argv[1:]

f = open(args[0])
x = getValue(int(f.readline()))
f.close()
# print(args)
# print(x)
for s in args[1:]:
	f = open(s)
	y = getValue(int(f.readline()))
	f.close()
	# print(y)
	if x != y:
		print(x, '!=', y)
		exit(1)
# print('All ok!')

