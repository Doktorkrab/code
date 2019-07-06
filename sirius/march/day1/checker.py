testF = open("test")
test = testF.readline().rstrip()
testF.close()

rightAns = open("corr_ans")
found = 1
try:
	lr, rr, llr, rrr = map(lambda x: int(x) - 1, rightAns.readline().split())
except ValueError:
	found = 0

rightAns.close()

myAns = open("corr_ans")
found1 = 1
try:
	lm, rm, llm, rrm = map(lambda x: int(x) - 1, myAns.readline().split())
except ValueError:
	found1 = 0
myAns.close()
if found != found1:
	1 / 0
if found == 0:
	exit(0)
a = 0
b = 0
for i in range(lm, rm + 1):
	a += ord(test[i]) - ord('0')


for i in range(llm, rrm + 1):
	b += ord(test[i]) - ord('0')

if lr - rr != lm - rm or llr - rrr != llm - rrm:
	1 / 0
if a != b:
	1 / 0
print('ok')