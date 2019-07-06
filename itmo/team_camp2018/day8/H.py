import sys

FN = 'h'
sys.stdin = open(FN + '.in')
sys.stdout = open(FN + '.out', 'w')


lines = [x.strip().rstrip().split() for x in sys.stdin.readlines()]
n = len(lines)
prefix = [0] * (n + 1)
ans = 0
for j in range(n):
    i = lines[j]
    if i[0] == "print":
        prefix[j + 1] = prefix[j] + int(i[1])
        ans += int(i[1])
    else:
        prefix[j + 1] = prefix[j]
        ans += (prefix[j] - prefix[int(i[1]) - 1]) * int(i[2])
print(ans)
