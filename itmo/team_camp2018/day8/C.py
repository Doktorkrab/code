import sys
sys.stdin = open("c.in")
sys.stdout = open("c.out", "w")

n = int(input())
arr = list(map(int, input().split()))
print(sum(arr) // 100)