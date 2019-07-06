n = int(input())
x = 0
for i in range(n):
    kek = int(input())
    x += pow(kek // 10, kek % 10)
print(x) 