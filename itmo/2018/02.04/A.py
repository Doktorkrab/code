import sys
FN = 'lights'
sys.stdin = open(FN + '.in')
sys.stdout = open(FN + '.out', 'w')
a, b, x = map(int, input().split())

if (x / 1000) % (a + b) <= a:
	print(1000)
elif (x / 1000 + a) % (a + b) <= a:
	print(1000)
else:
    print(x / (x / 1000 + a + b - ((x / 1000 + a) % (a + b))))