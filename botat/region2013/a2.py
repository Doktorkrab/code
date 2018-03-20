a, b, x = map(int, input().split())
if (x // 1000) % (a + b) < a or (x // 1000) % (a + b) == a and x % 1000 == 0:
    print(1000)
    exit(0) 
dt = (a + b) - (x / 1000 + a) % (a + b)
print(x / (x / 1000 + dt))