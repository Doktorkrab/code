def digit_sum(x):
    sum = 0
    while x > 0:
        sum += x % 10
        x //= 10
    return sum

def pref(x):
    return (x - digit_sum(x) % 2) // 2 + 1
a, b = map(int, input().split())

print(pref(b) - pref(a - 1))