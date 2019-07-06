import sys
sys.stdin = open('number.in')
sys.stdout = open('number.out', 'w')
s = input()
i = 0
cnt = 0
for i in range((len(s) - 1) // 2):
	if s[i + 1] != "0":
		cnt += 1
if (len(s) % 2 == 0):
	if (s[len(s) // 2] != "0" and int(s[:len(s) // 2]) <= int(s[len(s) // 2:])):
		cnt += 1
if  (s[0] == "0"):
	cnt = 0
print(cnt)