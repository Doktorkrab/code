import sys
FN = 'cube'
sys.stdin = open(FN + '.in')
sys.stdout = open(FN + '.out', 'w')
diagonal = set(['B1D', 'DB1', 'C1A', 'AC1', 'D1B', 'BD1', 'A1C', 'CA1'])
edges = [['AD1', 'D1A', 'A1D', 'DA1'], ['A1C1', 'C1A1', 'B1D1', 'D1B1'], ['DC1', 'C1D', 'D1C', 'CD1'], ['AC', 'CA', 'BD', 'DB'], ['AB1', 'B1A', 'A1B', 'BA1'], ['B1C', 'CB1', 'BC1', 'C1B']]
s = input()
s1 = input()
if s in diagonal and s1 in diagonal:
	print('Yes')
	exit(0)
cnt = -1
for i in range(6):
	if s in edges[i]:
		cnt = i
		break
cnt1 = -2
for i in range(6):
	if s1 in edges[i]:
		cnt1 = i
		break
if cnt1 == cnt:
	print('Yes')
	exit(0)
if len(s) == 2:
	s = [s[0], s[1]]
elif len(s) == 3:
	if s[1] == '1':
		s = [s[0] + s[1], s[2]]
	else:
		s = [s[0], s[1] + s[2]]
else:
	s = [s[0] + s[1], s[2] + s[3]]

if len(s1) == 2:
	s1 = [s1[0], s1[1]]
elif len(s1) == 3:
	if s1[1] == '1':
		s1 = [s1[0] + s1[1], s1[2]]
	else:
		s1 = [s1[0], s1[1] + s1[2]]
else:
	s1 = [s1[0] + s1[1], s1[2] + s1[3]]

if s[0] == s1[0] or s[1] == s1[0] or s[1] == s1[1] or s[0] == s1[1]:
	print('Yes')
	exit(0)
print('No')
